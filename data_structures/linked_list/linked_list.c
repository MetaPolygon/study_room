#include <stdlib.h>
#include "linked_list.h"

static void set(pNode node, const pData data, const pNode next) {
    node->info = data;
    node->next = next;
}

static pNode alloc(const pData data) {
    pNode temp = (pNode)calloc(1, sizeof(Node));
    set(temp, data, NULL);
    return temp;
}

void initialize(pList list) {
    list->cnt = 0;
    list->head = list->select = NULL;
}

//pNode search(const pList list, const pNode node);

void append(pList list, const pData data) {
    list->cnt++;
    pNode temp = list->head;
    if (temp != NULL) {
        while (temp->next != NULL)
            temp = temp->next;
        list->select = temp->next = alloc(data);
    }
    list->select = temp = alloc(data);    
}
void insert(pList list, const pData data, int idx) {
    list->cnt++;
    if (list->head == NULL || idx >= list->cnt) {
        append(list, data);
        return;
    }
    
    list->select = list->head;
    for (int i = 0; i < idx - 1; i++)
        list->select = list->select->next;
    pNode after = list->select->next->next; 
    list->select->next = alloc(data);
    list->select = list->select->next;
    list->select->next = after;
    
}
void print(const pList list);
void print_list(const pList list) {
    pNode temp = list->head;
    for (int i = 0; i < list->cnt; i++) {
        // printf("%d ", temp->info->age);
        // //temp = temp->next;
    }
}
void del(pList list);
void del_list(pList list);
