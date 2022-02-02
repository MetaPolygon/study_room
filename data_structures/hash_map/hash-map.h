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
pNode searchNode(const pChainHash hash, const pMember member);
int appendNode(pChainHash hash, const pMember member);
void printTable(pChainHash hash);
int deleteNode(pChainHash hash, const pMember member);
void deleteTable(pChainHash hash);
