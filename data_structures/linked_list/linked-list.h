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

int appendNode(pList list, const pMember member);
int insertNode(pList list, const pMember member, int idx);
pNode searchNode(const pList list, const pMember member);
void printNode(const pNode node);
void printList(const pList list);
void deleteNode(pList list);
void deleteList(pList list);
