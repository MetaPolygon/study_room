#include "Data.h"

typedef struct __node {
    Data info;
    struct __node *next;
}Node, *pNode;

typedef struct __list {
    pNode head;
    pNode temp;
}List, *pList;

void initialize(pList list);
pNode search(const pList list, const pNode node);
void add_node(pList list);
void print_node(const pList list);
void print_list(const pList list);
void del_node(pList list);
void del_list(pList list);
