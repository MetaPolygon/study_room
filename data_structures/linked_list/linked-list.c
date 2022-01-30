#include <stdlib.h>
#include "linked-list.h"

static void setNode(pNode node, const pMember member, const pNode next)
{
  node->member = member;
  node->next = next;
}

static pNode allocNode(const pMember member)
{
  pNode temp = (pNode)calloc(1, sizeof(Node));
  if(temp != NULL)
    setNode(temp, member, NULL);
  return temp;
}

static int findTail(pList list)
{
  if (list->head == NULL)
    return 0;
  pNode temp = list->head;
  int idx = 1;
  while (temp->next != NULL) {
    temp = temp->next;
      idx++;
  }
  list->tail = temp;
  return idx;
}

void initialize(pList list, pNode node)
{
  list->head = list->select = list->tail = node;
}

int appendNode(pList list, const pMember member)
{
  pNode temp = allocNode(member);
  if (temp != NULL && member != NULL) {
  	if (list->head != NULL)
      list->select = list->tail = list->tail->next = temp;
    else initialize(list, temp);
    return 0;
  }
  return -1;
}

int insertNode(pList list, const pMember member, int idx)
{
  if (list->head == NULL || findTail(list) < idx)
    return appendNode(list, member);
    
  pNode temp = allocNode(member);
  if (temp != NULL && member != NULL) {
    list->select = list->head;
  	for (int i = 0; i < idx - 2; i++)
      list->select = list->select->next;
    pNode after = list->select->next;
    if (idx == 1) {
      after = list->head;
      list->select = list->head = temp;
      temp->next = after;
      return 0;
    }
    list->select->next = temp;
    temp->next = after;
    list->select = list->select->next;
    return 0;
  }
  return -1;
}

pNode searchNode(const pList list, const pMember member)
{
  pNode temp = list->head;
  while (temp != NULL) {
    if (cmpMember(member, temp->member, NO) == 0) {
      list->select = temp;
      break;
    }
    temp = temp->next;
  }
  return temp;
}

void printNode(const pNode node)
{
  printf("\n ----<node>----");
  printMember(node->member);
  puts(    " --------------");
}

void printList(const pList list)
{
  pNode temp = list->head;
  puts("\n=====[list]=====");
  while (temp != NULL) {
    printNode(temp);
    temp = temp->next;
  }
  puts("\n================");
}

void deleteNode(pList list)
{
  if (list->head != NULL) {
    if (list->head == list->select) {
      free(list->head);
      initialize(list, NULL);
      return;
    }
        
    pNode temp = list->head;
    while (temp->next != list->select)
      temp = temp->next;
    pNode after = list->select->next;
    free(list->select);
    list->select = NULL;
    temp->next = after;
    findTail(list);
  }
}

void deleteList(pList list)
{
  while(list->head != NULL)
    if (list->head != NULL) {
      pNode after = list->head->next;
      free(list->head);
      list->head = after;
    }
}
