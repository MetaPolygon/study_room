#include "member.h"

typedef struct __Node {
  pMember member;
  struct __Node *next;
}Node, *pNode;

typedef struct __List {
  pNode head;
  pNode select;
  pNode tail;
} List, *pList;

void initialize(pList list, pNode node);
pNode searchNode(const pList list, const pNode node);
int appendNode(pList list, const pMember member);
int insertNode(pList list, const pMember member, int idx);
void printNode(const pNode node);
void printList(const pList list);
void delNode(pList list);
void delList(pList list);
