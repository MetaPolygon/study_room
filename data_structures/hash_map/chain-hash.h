#include "member.h"

struct __Node
{
  pMember member;
  struct __Node *next;
};
typedef struct __Node Node, *pNode;

struct __ChainHash
{
  int size;
  pNode *table;
};
typedef struct __ChainHash ChainHash, *pChainHash;

int initialize(pChainHash hash, int size);
int appendNode(pChainHash hash, const pMember member);
pNode searchNode(const pChainHash hash, const pMember member);
void printNode(const pNode node);
void printTable(pChainHash hash);
void deleteNode(pChainHash hash, const pMember member);
void deleteTable(pChainHash hash);
