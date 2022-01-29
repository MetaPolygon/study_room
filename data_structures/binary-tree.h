#include "member.h"

struct __BinaryNode
{
  pMember member;
  struct __BinaryNode *left;
  struct __BinaryNode *right;
}
typedef struct __BinaryNode BNode, *pBNode;

pBNode searchNode(const pBNode node, const pMember member);
pBNode insertNode(pBnode node, const pMember member);
int delNode(pBnode node, const pMember member)
void printTree(pBnode root);
void freeTree(pBnode root);
