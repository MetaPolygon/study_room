#include "hash-map.h"

static int getKey(int key, int size)
{
  return key % size;
}

static pNode* allocBucket(int size)
{
  return (pNode*)calloc(size, sizeof(pNode));
}

static pNode allocNode()
{
  return (pNode)calloc(1, sizeof(Node));
}

static void setNode(pNode node, const pMember member, const pNode next)
{
  node->member = member;
  node->next = next;
}

int initialize(pChainHash hash, int size)
{
  if ((hash->table = allocBucket(size)) != NULL) {
    hash->size = size;
    for (int i = 0; i < size; i++)
      hash->table[i] = NULL;
    return 0;
  }
  hash->size = 0;
  return -1;
}

pNode searchNode(const pChainHash hash, const pMember member)
{
  pNode temp = hash->table[getKey(member->no, hash->size)];
  while (temp != NULL) {
    if (temp->member->no == member->no)
      return temp;
    temp = temp->next;
  }
  return NULL;
}

int appendNode(pChainHash hash, const pMember member)
{
  int key = getKey(member->no, hash->size);
  pNode temp;
  if ((temp = allocNode()) != NULL) {
    setNode(temp, member, hash->table[key]);
    hash->table[key] = temp;
    return 0;
  }
  return -1;
}

void printTable(pChainHash hash)
{
  for (int i = 0; i < hash->size; i++) {
    pNode temp = hash->table[i];
    printf("  [%d] : ", i);
    while (temp != NULL) {
      printf("%d ", temp->member->no);
      temp = temp->next;
    }
    putchar(10);
  }
}

int deleteNode(pChainHash hash, const pMember member)
{
  int key = getKey(member->no, hash->size);
  pNode temp = hash->table[key];
  pNode *ptemp = &hash->table[key];
  while (temp != NULL) {
    if (temp->member->no == member->no) {
      *ptemp = temp->next;
      free(temp);
      return 0;
    }
    ptemp = &temp->next;
    temp = temp->next;
  }
  return -1;
}

void deleteTable(pChainHash hash)
{
  for (int i = 0; i < hash->size; i++) {
    pNode temp = hash->table[i];
    while (temp != NULL) {
      pNode after = temp->next;
      free(temp);
      temp = after;
    }
  }
  free(hash->table);
  hash->size = 0;
}
