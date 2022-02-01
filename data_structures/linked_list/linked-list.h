#include "member.h"

struct __Node
{
  pMember member;
  struct __Node *next;
};
typedef struct __Node Node, *pNode;

struct __List
{
  pNode head;
  pNode select;
  pNode tail;
};
typedef struct __List List, *pList;

void initialize(pList list, pNode node);
int appendNode(pList list, pNode node, const pMember member);
int insertNode(pList list, const pMember member);
pNode searchNode(const pList list, const pMember member);
void printNode(const pNode node);
void printList(const pList list);
void deleteNode(pList list);
void deleteList(pList list);
