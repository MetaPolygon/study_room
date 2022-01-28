#include <stdio.h>
#include "Data.h"

typedef struct __node {
    Data info;
    struct __node *next;
}Node, *pNode;

typedef struct __list {
    pNode head;
    pNode select;
    pNode tail;
}List, *pList;

void initialize(pList list);
pNode search(const pList list, const pNode node);
int append(pList list, const pData data);
int insert(pList list, const pData data, int idx);
void print(const pList list);
void print_list(const pList list);
void del(pList list);
void del_list(pList list);
