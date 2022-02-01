#include "double-circular-linked-list.h"
static pDNode allocDNode()
{
  return (pDNode)calloc(1, sizeof(DNode));
}

static int isEmpty(const pDList list)
{
  return list->head->next == list->head;
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

int appendDNode(pDList list, pDNode node, const pMember member)
{
  pDNode temp = allocDNode(), after;
  if (temp != NULL) {
    after = node->next;
    node->next = node->next->prev = temp;
    setDNode(temp, member, node, after);
    list->select = temp;
    return 0;
  }
  return -1;
}

int insertDNode(pDList list, const pMember member)
{
  if (isEmpty(list))
    return appendDNode(list, list->head, member);
  if (list->select != NULL)
    return appendDNode(list, list->select, member);
  return -1;
}

pDNode searchDNode(pDList list, const pMember member)
{
  pDNode temp = list->head->next;
  while (temp != list->head) {
    if (cmpMember(member, temp->member, NO) == 0)
      return list->select = temp;
    temp = temp->next;
  }
  puts("  No matching search node");
  list->select = NULL;
  return NULL;
}

void printDNode(const pDList list)
{
  if (list->select != NULL)
    printMember(list->select->member);
  else puts("  Node not Selected");
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

void deleteDNode(pDList list)
{
  if (list->select != list->head) {
    pDNode temp = list->select;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(list->select);
    list->select = temp->prev;
  }
}

void deleteDList(pDList list)
{
  while(!isEmpty(list))
    deleteDNode(list);
}
