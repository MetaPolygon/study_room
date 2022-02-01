#include "member.h"
struct __DNode
{
  pMember member;
  struct __DNode *prev, *next;
};
typedef struct __DNode DNode, *pDNode;

struct __DList
{
  pDNode head, select;
};
typedef struct __DList DList, *pDList;

void initialize(pDList list);
int appendDNode(pDList list, pDNode node, const pMember member);
int insertDNode(pDList list, const pMember member);
pDNode searchDNode(pDList list, const pMember member);
void printDNode(const pDList list);
void printDList(const pDList list);
void deleteDNode(pDList list);
void deleteDList(pDList list);
