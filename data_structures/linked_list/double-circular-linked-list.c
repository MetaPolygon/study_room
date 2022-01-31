#include "double-circular-linked-list.h"

static pDNode allocDNode()
{
  return (pDNode)calloc(1, sizeof(DNode));
}

static void setDNode(pDNode node, const pMember member,
                     const pDNode prev, const pDNode next)
{
  node->member = member;
  node->prev = prev;
  node->next = next;
}

void initialize(pDList list)
{
  pDNode dummy = allocDNode();
  list->head = list->select = dummy;
  dummy->prev = dummy->next = dummy;
}

void printDNode(const pDList list)
{
  if (list->select != NULL)
    printMember(list->select->member);
  else puts("  Node not Selected");
}

pDNode searchDNode(pDList list, const pMember member)
{
  pDNode temp = list->head->next;
  while (temp != list->head) {
    if (cmpMember(member, temp->member, NO) == 0)
      return list->select = temp;
    temp = temp->next;
  }
  return NULL;
}

void printDList(const pDList list)
{
  if (list->select != NULL) {
    pDNode temp = list->head->next;
    while (temp != list->head) {
      printMember(temp->member);
      temp = temp->next;
    }
  }
}
