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
void printDNode(const pDList list);
pDNode searchDNode(pDList list, const pMember member);
void printDList(const pDList list);
