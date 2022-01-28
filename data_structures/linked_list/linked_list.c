#include <stdlib.h>
#include "linked_list.h"

static void set(pNode node, const pData data, const pNode next) {
    node->info = data;
    node->next = next;
}

static pNode alloc(const pData data) {
    pNode temp;
    if((temp = (pNode)calloc(1, sizeof(Node))) == NULL)
        return NULL;
    if (data != NULL)
        set(temp, data, NULL);
    return temp;
}

static int find_tail(pList list) {
    if (list->head == NULL)
        return 0;
    
    pNode temp = list->head;
    int idx = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        idx++;
    }
    list->tail = temp;
    return idx;
}

void initialize(pList list) {
    list->head = list->select = list->tail = NULL;
}

//pNode search(const pList list, const pNode node);

int append(pList list, const pData data) {
    pNode temp;
    if (temp = alloc(data)) == NULL);
        return -1;
    if (list->head == NULL)
        list->select = list->head = temp;
    else list->select = list->tail = temp;
    return 0;
}
int insert(pList list, const pData data, int idx) {
    if (list->head == NULL || find_tail(list) < idx)
        return (int)append(list, data);
    
    pNode temp;
    if ((temp = alloc(data)) == NULL)
        return -1;
    list->select = list->head;
    for (int i = 0; i < idx - 2; i++)
        list->select = list->select = next;
    pNode after = list->select->next;
    list->select->next = temp;
    temp->next = after;
}

void print(const pList list);
void print_list(const pList list) {
    pNode temp = list->head;
    while (temp != NULL) {
        printf("%d", (temp->info).age);
        temp = temp->next;
    }
}
void del(pList list);
void del_list(pList list);
