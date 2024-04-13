//
// Created by Hank on 2024/4/10.
//

#ifndef C_PROCESS_COMBO_H
#define C_PROCESS_COMBO_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"

#    define PROGMEM
#    define pgm_read_word(address_short) *((uint16_t*)(address_short))

//According to your need to modify the constants.
#define TICKS_INTERVAL    5	//ms
#define DEBOUNCE_TICKS    3	//MAX 7 (0 ~ 7)
#define SHORT_TICKS       (300 /TICKS_INTERVAL)
#define LONG_TICKS        (2500 /TICKS_INTERVAL)

// 组合键结束标志
#define COMBO_END 0
/**
  * @brief  事件触发后回调函数
  * @param  uint16_t* arr: 长度为10的数组，用于记录组合键
  * @retval uint8_t: 返回新增键的个数
  */
typedef uint8_t (*BtnCallback)(uint16_t* add_keys);

// 按键事件种类
typedef enum {
    PRESS_DOWN = 0, // 按下
    PRESS_UP, // 释放
    PRESS_REPEAT, // 重复
    SINGLE_CLICK, // 单击
    DOUBLE_CLICK, // 双击
    LONG_PRESS_START, // 长按开始
    LONG_PRESS_HOLD, // 长按保持
    number_of_event, // 事件数量
    NONE_PRESS //   无事件
}PressEvent;

// 组合键对象
typedef struct combo_t {
    const uint16_t *keys; // 记录组合键 按键
    bool  disabled; // 记录是否禁用
    uint16_t ticks; // 记录点击次数
    uint8_t  repeat : 4; // 记录重复次数
    uint8_t  event : 4; // 记录触发的事件
    uint8_t  state : 6; // 按键状态机记录
    uint8_t  active_status : 1; // 判断组合键是否激活
    uint8_t  button_level : 1; // 记录当前电平
    uint16_t long_press_ticks; // 长按时间阈值
    BtnCallback cb[number_of_event]; // 回调函数
} combo_t;

#define COMBO(ck, event_idx,callback) { .keys = &(ck)[0], .cb[event_idx] = (callback) ,.event=(uint8_t)NONE_PRESS,\
        .long_press_ticks= LONG_TICKS,.event=(uint8_t)NONE_PRESS,.state = 0}
#define COMBO2(ck, event_idx1,callback1, event_idx2,callback2) \
    { .keys = &(ck)[0], .cb[event_idx1] = (callback1),.cb[event_idx2] = (callback2),.event=(uint8_t)NONE_PRESS ,\
    .long_press_ticks= LONG_TICKS,.event=(uint8_t)NONE_PRESS,.state = 0}
#define COMBO3(ck, event_idx1,callback1, event_idx2,callback2, event_idx3,callback3) \
    { .keys = &(ck)[0], .cb[event_idx1] = (callback1),.cb[event_idx2] = (callback2),.cb[event_idx3] = (callback3) ,\
    .event=(uint8_t)NONE_PRESS,.long_press_ticks= LONG_TICKS,.event=(uint8_t)NONE_PRESS,.state = 0}
#define COMBO_LONG_TICKS(ck,long_tick, event_idx,callback) \
    { .keys = &(ck)[0], .cb[event_idx] = (callback) ,.event=(uint8_t)NONE_PRESS,\
    .long_press_ticks=(uint16_t)(long_tick / TICKS_INTERVAL),.event=(uint8_t)NONE_PRESS,.state = 0}
#define COMBO2_LONG_TICKS(ck,long_tick, event_idx1,callback1, event_idx2,callback2) \
    { .keys = &(ck)[0], .cb[event_idx1] = (callback1),.cb[event_idx2] = (callback2),.event=(uint8_t)NONE_PRESS,\
    .long_press_ticks=(uint16_t)(long_tick / TICKS_INTERVAL) ,.event=(uint8_t)NONE_PRESS,.state = 0}
#define COMBO3_LONG_TICKS(ck,long_tick, event_idx1,callback1, event_idx2,callback2, event_idx3,callback3) \
    { .keys = &(ck)[0], .cb[event_idx1] = (callback1),.cb[event_idx2] = (callback2),.cb[event_idx3] = (callback3) ,\
    .event=(uint8_t)NONE_PRESS,.long_press_ticks=(uint16_t)(long_tick / TICKS_INTERVAL),.event=(uint8_t)NONE_PRESS,.state = 0}

/**
  * @brief  处理组合键任务
  */
void combo_task(key_update_st_t _keyUpdateSt);

#endif //C_PROCESS_COMBO_H
