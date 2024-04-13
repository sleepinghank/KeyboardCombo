#include <stdio.h>
#include "keyboard/process_combo.h"
#include "keyboard/linkedlist.h"

list_t* _key_code_list;
list_t* _key_code_list_extend;

int init(void){
    _key_code_list = make_list_proc();
    _key_code_list_extend = make_list_proc();
    add(KB_OPEN_BRACKET_N_BRANCE, _key_code_list);
    add(KB_A, _key_code_list);
    add(KB_B, _key_code_list);
    add(KB_C, _key_code_list);
    add(KB_CLOSE_BRACKET_N_BRANCE, _key_code_list);
};

extern combo_t key_combos[];
extern uint8_t active_event;

int main() {
    init();
    node_t* current = _key_code_list->head;
    node_t* curr_tmp = current;

    printf("combo task befor\r\nKeys:");
    while (current != NULL) {
        uint16_t keycode = current->data.key_code;
        printf("0x%02X,", keycode);
        current = current->next;
    }
    printf("\r\n");

    combo_task(KEY_UPDATE);

    printf("combo task end\r\nKeys:");
    uint8_t is_extend = 0;
    current = _key_code_list->head;

    while (current != NULL) {
        curr_tmp = current;
        current = current->next;
        if (current == NULL && active_event == 1 && is_extend == 0) {
            current = _key_code_list_extend->head;
            is_extend = 1;
        }
        if (curr_tmp->data.is_report == 0) {
            continue;
        }
        uint16_t keycode = curr_tmp->data.key_code;
        printf("0x%02X,", keycode);
    }
    return 0;
}
