#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#pragma anon_unions

#include <stdint.h>

typedef struct node node_t;

typedef struct list list_t;

typedef enum _report_t
{
    NONE_RPT            = 0,
    NORMAL_RPT      = 1,
    FUNCTION_RPT    = 2,
} report_t;

typedef struct
{
    uint16_t key_code;
    uint8_t cycle;
    uint8_t is_report;
    report_t report_type;
} bouncing_data_t;

struct node
{
    bouncing_data_t data;
    node_t* next;
};

struct list
{
    node_t* head;
};

list_t* make_list_proc(void);
void add(uint16_t data, list_t* list);
void del(uint16_t data, list_t* list);
void deactivate(uint16_t data, list_t* list);
void del_all_child(list_t* list);
void display(list_t* list);
void reverse(list_t* list);
void destroy(list_t* list);
void increase_cycle(list_t* list);
void pop_key(list_t* list, uint16_t* key, uint8_t* sz, uint8_t cycle_limit);
uint8_t find_key(list_t* list, uint16_t key);
uint8_t insert_key(list_t* list, uint16_t _pre, uint16_t _new);
#endif
