#include "binary-tree.h"

static pBNode allocBNode()
{
  return (pBNode)calloc(1, sizeof(BNode));
}

static void setBNode(pBNode node, const pMember member,
                     const pBNode left, const pBNode right)
{
  node->member = member;
  node->left = left;
  node->right = right;
}

pBNode addBNode(pBNode node, const pMember member)
{
  int child;
  if (node == NULL)
    setBNode(node = allocBNode(), member, NULL, NULL);
  else if ((child = cmpMember(member, node->member, NO)) == 0)
    puts("same node exists");
  else if (child < 0) node->left = addBNode(node->left, member);
  else node->right = addBNode(node->right, member);
  return node;
}

pBNode searchBNode(pBNode node, const pMember member)
{
  if (node != NULL) {
    int child;
    if ((child = cmpMember(member, node->member, NO)) == 0)
      return node;
    else if (child < 0) return searchBNode(node->left, member);
    else return searchBNode(node->right, member);
  }
  return NULL;
}

void printTree(const pBNode root)
{
  if (root != NULL) {
    printTree(root->left);
    printMember(root->member);
    printTree(root->right);
  }
}

int deleteBNode(BNode **root, const pMember member)
{
  pBNode after, temp;
  BNode **select = root, **left;
  int child;
  while (1) {
    if (*select == NULL) {
      puts("not in");
      return -1;
    } else if ((child = cmpMember(member, (*select)->member, NO)) == 0)
      break;
    else if (child < 0) select = &((*select)->left);
    else select = &((*select)->right);
  }
  
  if ((*select)->left == NULL) after = (*select)->right;
  else {                                // Search for node smaller than selected node.
    left = &((*select)->left);          // left child is always smaller than the parent
                                        // right child of the left child is equal to or smaller than the parent
    while ((*left)->right != NULL) 
      left = &(*left)->right;
                                        //linked 
    after = *left;
    *left = (*left)->left;
    after->left = (*select)->left;
    after->right = (*select)->right;
  }
  temp = *select;
  *select = after;
  free(temp);
  return 0;
}

void deleteTree(pBNode root)
{
  if (root != NULL) {
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
  }
}
