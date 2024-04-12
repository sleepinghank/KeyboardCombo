# KeyboardCombo

## 简介

KeyboardCombo 是在获取按键链表后执行负责组合键逻辑，可无限扩展，按键事件回调可以简化你的程序结构，专注于组合键业务。

## 使用方式

```c
enum combos {
    AB_ESC,
    CD_ESC,
    EF_ESC,
    combos_end,
};
uint8_t number_of_combos = combos_end;

// 组合键触发后的回调函数，arr为触发的按键
uint8_t BtnCallback1(uint16_t* add_keys){
    uint8_t idx = 0;
    add_keys[idx++] = KB_1;
    add_keys[idx++] = KB_2;
    return idx;
}
// 组合键触发后的回调函数，arr为触发的按键
uint8_t BtnCallback2(uint16_t* add_keys){
    uint8_t idx = 0;
    add_keys[idx++] = KB_3;
    add_keys[idx++] = KB_4;
    return idx;
}


const uint16_t PROGMEM ab_combo[] = {KB_A, KB_B, COMBO_END};
const uint16_t PROGMEM cd_combo[] = {KB_C, KB_D, COMBO_END};
const uint16_t PROGMEM ef_combo[] = {KB_E, KB_F, COMBO_END};

combo_t key_combos[] = {
        [AB_ESC] = COMBO(ab_combo,PRESS_DOWN,BtnCallback1),
        [CD_ESC] = COMBO2(cd_combo,PRESS_UP,BtnCallback1,LONG_PRESS_HOLD,BtnCallback2),
        [EF_ESC] = COMBO_LONG_TICKS(ef_combo,600,LONG_PRESS_HOLD, BtnCallback1),
};

```

## 感谢

[qmk](https://github.com/qmk/qmk_firmware.git) 

[MultiButton](https://github.com/0x1abin/MultiButton.git)

