#include <stdlib.h>
#include "linked-list.h"

static void setNode(pNode node, const pMember member, const pNode next)
{
  node->member = member;
  node->next = next;
}

static pNode allocNode(const pMember member)
{
  pNode temp = calloc(1, sizeof(Node));
  if(temp == NULL)
    return NULL;
    if (member != NULL)
      setNode(temp, member, NULL);\
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

void initialize(pList list, pNode node) { list->head = list->select = list->tail = node; }

//pNode search(const pList list, const pNode node);

int appendNode(pList list, const pMember member)
{
  pNode temp = allocNode(member);
  if (temp == NULL)
    return -1;
  if (list->head == NULL)
    initialize(list, temp);
  else list->select = list->tail = list->tail->next = temp;
  return 0;
}

int insertNode(pList list, const pMember member, int idx)
{
  if (list->head == NULL || findTail(list) < idx)
    return (int)appendNode(list, member);
    
  pNode temp = allocNode(member);
  if (temp == NULL)
    return -1;
  list->select = list->head;
  for (int i = 0; i < idx - 2; i++)
    list->select = list->select->next;
  pNode after = list->select->next;
  list->select->next = temp;
  temp->next = after;
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

void delNode(pList list)
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
    temp->next = after;
    findTail(list);
  }
}

void delList(pList list)
{
}
