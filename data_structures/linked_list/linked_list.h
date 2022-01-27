#include <stdio.h>
#include "Data.h"

typedef struct __node {
    pData info;
    struct __node *next;
}Node, *pNode;

typedef struct __list {
    int cnt;
    pNode head;
    pNode select;
}List, *pList;

void initialize(pList list);
pNode search(const pList list, const pNode node);
void append(pList list, const pData data);
void insert(pList list, const pData data, int idx);
void print(const pList list);
void print_list(const pList list);
void del(pList list);
void del_list(pList list);
