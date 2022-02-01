#include "member.h"

struct __BNode
{
  pMember member;
  struct __BNode *left, *right;
};
typedef struct __BNode BNode, *pBNode;

pBNode addBNode(pBNode node, const pMember member);
pBNode searchBNode(pBNode node, const pMember member);
void printTree(const pBNode root);
int deleteBNode(BNode **root, const pMember member);
void deleteTree(pBNode root);
