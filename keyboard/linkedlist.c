#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include <string.h>
#include <stdint.h>

node_t* create_node(bouncing_data_t data);

node_t* create_node(bouncing_data_t data)
{
    node_t* new_node = malloc(sizeof(node_t));

    if (!new_node)
        return NULL;

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

list_t* make_list_proc()
{
    list_t* list = malloc(sizeof(list_t));

    if (!list)
        return NULL;

    list->head = NULL;
    return list;
}

void display(list_t* list)
{
    node_t* current = list->head;

    if (list->head == NULL)
        return;

    for (; current != NULL; current = current->next)
        printf("Key,Cycle(%02X,%02X)\r\n", current->data.key_code, current->data.cycle);

    printf("\r\n");
}

void add(uint16_t data, list_t* list)
{
    node_t* current = NULL;
    bouncing_data_t bouncing_data;
    memset((uint8_t*)&bouncing_data, 0x00, sizeof(bouncing_data));

    bouncing_data.key_code = data;
    bouncing_data.is_report = 1;
    if (list->head == NULL)
        list->head = create_node(bouncing_data);
    else
    {
        current = list->head;
        // Prevent duplicate addition
        while (current->next != NULL){
            current = current->next;
        }

        current->next = create_node(bouncing_data);
    }
}
void deactivate(uint16_t data, list_t* list)
{
    node_t* current = list->head;

    while (current != NULL)
    {
        if (current->data.key_code == data)
        {
            current->data.is_report = 0;
            return;
        }

        current = current->next;
    }
}
void del(uint16_t data, list_t* list)
{
    node_t* current = list->head;
    node_t* previous = current;

    while (current != NULL)
    {
        if (current->data.key_code == data)
        {
            previous->next = current->next;

            if (current == list->head)
                list->head = current->next;

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

void reverse(list_t* list)
{
    node_t* reversed = NULL;
    node_t* current = list->head;
    node_t* temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        temp->next = reversed;
        reversed = temp;
    }

    list->head = reversed;
}

void destroy(list_t* list)
{
    node_t* current = list->head;
    node_t* next = current;

    if (list == NULL)
        return;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void delete_node(node_t* node)
{
    if (node == NULL)
        return;

    delete_node(node->next);
    free(node);
}
void del_all_child(list_t* list)
{
    // 保存头节点
    node_t* head = list->head;
    delete_node(head);
    list->head = NULL;
}

void increase_cycle(list_t* list)
{
    node_t* current = list->head;
    node_t* next = current;

    while (current != NULL)
    {
        current->data.cycle++;
        next = current->next;
        current = next;
    }
}

void pop_key(list_t* list, uint16_t* key, uint8_t* sz, uint8_t cycle_limit)
{
    node_t* current = list->head;
    node_t* previous = current;
    uint8_t idx = 0;
    *sz = 0;

    while (current != NULL)
    {
        if (current->data.cycle >= cycle_limit)
        {
            previous->next = current->next;
            key[idx++] = current->data.key_code;
            *sz = *sz + 1;

            if (*sz >= 20)
                return;

            if (current == list->head)
                list->head = current->next;

            free(current);
            current = previous->next;
            continue;
        }

        previous = current;
        current = current->next;
    }
}

uint8_t find_key(list_t* list, uint16_t key)
{
    node_t* current = list->head;
    node_t* next = current;

    while (current != NULL)
    {
        if (current->data.key_code == key)
            return 1;

        next = current->next;
        current = next;
    }

    return 0;
}

uint8_t insert_key(list_t* list, uint16_t pre, uint16_t n)
{
    node_t* current = list->head;
    node_t* next = current;

    while (current != NULL)
    {
        next = current->next;

        if (current->data.key_code == pre)
        {
            bouncing_data_t bouncing_data = {0x00};
            bouncing_data.key_code = n;
            current->next = create_node(bouncing_data);
            current->next->next = next;
            return 1;
        }

        current = next;
    }

    return 0;
}

