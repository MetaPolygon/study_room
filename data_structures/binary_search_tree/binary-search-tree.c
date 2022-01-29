#include "binary-search-tree.h"

static pBNode allocNode()
{
  return (pBNode)calloc(1, sizeof(BNode));
}

static void setNode(pBNode node, const pMember member,
                    const pBNode left, const pBNode right)
{
  node->member = member;
  node->left = left;
  node->right = right;
}

pBinaryNode searchNode(const pBNode node, const pMember member)
{
  int temp;
  if (node == NULL || temp = cmpMember(member, node->member) == 0)
    return node; 
  else if (temp < 0)
    searchNode(node->left);
  else searchNode(node -> right);
}

pBinaryNode insertNode(pBnode node, const pMember member);
int delNode(pBnode node, const pMember member)
void printTree(pBnode root);
void freeTree(pBnode root);
