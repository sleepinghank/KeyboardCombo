//
// Created by Hank on 2024/4/10.
//

#include "process_combo.h"
#include "linkedlist.h"
#include <string.h>

#    define COMBO_DISABLED(combo) (combo->disabled)


#define ALL_COMBO_KEYS_ARE_DOWN(state, key_count) (((1 << key_count) - 1) == state)

#define KEY_STATE_DOWN(state, key_index) \
    do {                                 \
        state |= (1 << key_index);       \
    } while (0)
#define KEY_STATE_UP(state, key_index) \
    do {                               \
        state &= ~(1 << key_index);    \
    } while (0)
#define PRESS_REPEAT_MAX_NUM  15 /*!< The maximum value of the repeat counter */

extern list_t* _key_code_list;          // current press key
extern list_t* _key_code_list_extend;          // current press key
extern combo_t key_combos[];

/**
  * @brief  组合键触发后，按键状态机判断
  * @param  combo_t *combo: 组合键对象
  */
void button_ticks(combo_t *combo);
/**
  * @brief  从_key_code_list中删除激活的组合键
  * @param  combo_t *combo: 组合键对象
  */
void del_combo_keys(const uint16_t *keys);
/**
  * @brief  将激活的组合键加入_key_code_list中
  * @param  combo_t *combo: 组合键对象
  * @param  uint16_t* arr: 数组指针，全局缓存数组，防止重复申请内存
  */
void add_combo_result(const combo_t *combo,uint16_t* arr);
/**
  * @brief  判断组合键是否触发
  * @param  uint16_t combo_index: 组合键索引
  * @param  combo_t *combo: 组合键对象
  */
void apply_combo(uint16_t combo_index, combo_t *combo);

/**
  * @brief  查找键在当前组合键中索引和总计数
  * @param  const uint16_t *keys: 组合键数组
  * @param  uint16_t keycode: 当前按键
  * @param uint16_t *key_index: 当前按键索引指针
  * @param uint8_t *key_count: 当前按键总数指针
  */
static void _find_key_index_and_count(const uint16_t *keys, uint16_t keycode, uint16_t *key_index, uint8_t *key_count) {
    while (true) {
        uint16_t key = pgm_read_word(&keys[*key_count]);
        if (keycode == key) *key_index = *key_count;
        if (COMBO_END == key) break;
        (*key_count)++;
    }
}

void apply_combo(uint16_t combo_index, combo_t *combo) {
    node_t* current = _key_code_list->head;
    uint8_t state = 0;
    if (COMBO_DISABLED(combo)) {
        return ;
    }
    combo -> active_status = 0;
    while (current != NULL) {
        uint16_t keycode = current->data.key_code;
        uint8_t  key_count = 0;
        uint16_t key_index = -1;
        _find_key_index_and_count(combo->keys, keycode, &key_index, &key_count);

        if (-1 == (int16_t)key_index) {
            // key not part of this combo
            current = current->next;
            continue;
        }
        KEY_STATE_DOWN(state, key_index);
        if (ALL_COMBO_KEYS_ARE_DOWN(state, key_count)) {
            // All keys are down
            combo -> active_status = 1;
            return ;
        }
        current = current->next;
    }
}


void button_ticks(combo_t *combo) {
    //ticks counter working..
    if((combo->state) > 0) combo->ticks++;

    /*------------button debounce combo---------------*/
    if(combo -> active_status != combo->button_level) { //not equal to prev one
        combo->button_level = combo -> active_status;
    }

    /*-----------------State machine-------------------*/
    switch (combo->state) {
        case 0:
            if(combo->button_level == 1) {	//start press down
                combo->event = (uint8_t)PRESS_DOWN;
                combo->ticks = 0;
                combo->repeat = 1;
                combo->state = 1;
            } else {
                combo->event = (uint8_t)NONE_PRESS;
            }
            break;

        case 1:
            if(combo->button_level != 1) { //released press up
                combo->event = (uint8_t)PRESS_UP;
                combo->ticks = 0;
                combo->state = 2;
            } else if(combo->ticks > combo->long_press_ticks) { // Customize the long press duration
                combo->event = (uint8_t)LONG_PRESS_START;
                combo->state = 5;
            }
            break;

        case 2:
            if(combo->button_level == 1) { //press down again
//                combo->event = (uint8_t)PRESS_DOWN;
                if(combo->repeat != PRESS_REPEAT_MAX_NUM) {
                    combo->repeat++;
                }
                combo->event = (uint8_t)PRESS_REPEAT;
                combo->ticks = 0;
                combo->state = 3;
            } else if(combo->ticks > SHORT_TICKS) { //released timeout
                if(combo->repeat == 1) {
                    combo->event = (uint8_t)SINGLE_CLICK;
                } else if(combo->repeat == 2) {
                    combo->event = (uint8_t)DOUBLE_CLICK;
                }
                combo->state = 0;
            }
            break;

        case 3:
            if(combo->button_level != 1) { //released press up
                combo->event = (uint8_t)PRESS_UP;
                if(combo->ticks < SHORT_TICKS) {
                    combo->ticks = 0;
                    combo->state = 2; //repeat press
                } else {
                    combo->state = 0;
                }
            } else if(combo->ticks > SHORT_TICKS) { // SHORT_TICKS < press down hold time < LONG_TICKS
                combo->state = 1;
            }
            break;

        case 5:
            if(combo->button_level == 1) {
                //continue hold trigger
                combo->event = (uint8_t)LONG_PRESS_HOLD;
            } else { //released
                combo->event = (uint8_t)PRESS_UP;
                combo->state = 0; //reset
            }
            break;
        default:
            combo->state = 0; //reset
            break;
    }
}

void add_combo_result(const combo_t *combo,uint16_t* buf) {
    memset(buf, 0, 10);
    {
        uint8_t u8temp;
        uint8_t idx = combo->cb[combo->event](buf);
        for (u8temp = 0; u8temp < idx; ++u8temp) {
            add(buf[u8temp], _key_code_list_extend);
        }
    }
}

void del_combo_keys(const uint16_t *keys) {
    uint8_t key_count = 0;
    while (true) {
        uint16_t key = pgm_read_word(&keys[key_count]);
        if (COMBO_END == key) break;
        deactivate(key, _key_code_list);
        key_count++;
    }
}
extern uint8_t number_of_combos;
uint8_t active_event = 0;
// 按键事件处理
// 1. 循环key_combos，从_key_code_list中判断是否满足组合键条件
// 2. 满足函数进行按键状态机处理，判断满足状态的事件
// 3. 满足事件后，调用回调函数，从_key_code_list中删除组合键，添加新增的键。
void combo_task(key_update_st_t _keyUpdateSt){
    uint8_t u8temp ;
    uint16_t buf[10] = {0};
    
    if (_keyUpdateSt == GHOST_KEY){
        return;
    }
    // 清空所有扩展键
    del_all_child(_key_code_list_extend);
    active_event = 0;
    // 循环所有事件，逐个进行处理
    for (u8temp = 0; u8temp < number_of_combos; ++u8temp) {
        combo_t *combo = &key_combos[u8temp];
        // 判断是否触发组合
        apply_combo(u8temp, combo);
        // 按键状态机处理
        button_ticks(combo);
        // 判断是否执行事件
        if (combo->event < number_of_event  && combo->cb[combo->event]) {
            // 事件触发,通知添加新的键
            active_event = 1;
            // 先删除组合键，删除的组合键不再上报，但是还是可以组成组合键
            del_combo_keys(combo->keys);
            // 添加新的键
            add_combo_result(combo,buf);
            // 重置组合键状态
            combo->event = (uint8_t)NONE_PRESS;
        } else if(combo -> active_status == 1) {
            // 组合键激活，但是没有事件，删除组合键
            del_combo_keys(combo->keys);
        }
    }
}