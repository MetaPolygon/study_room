
#include "binary-tree.h"

enum __eMenu
{
  EXIT,
  ADD,
  SEARCH,
  PRINT_TREE,
  DEL_BNODE,
};
typedef enum __eMenu Menu;

Menu selectMenu(const char *[]);

int main()
{
  const char* menu_list[] = {
    "| Exit                  |",
    "| Add Node              |",	
    "| Search Node           |",
    "| All Print Node Info   |",
    "| Delete Node           |",
  };
  Menu menu;
  pBNode root = NULL;
  do {
    pBNode temp;
    switch (menu = selectMenu(menu_list)) {
      case ADD:
        root = addBNode(root, scanMember(NO));
        break;
        
      case SEARCH:
        if ((temp = searchBNode(root, scanMember(NO))) != NULL)
          printMember(temp->member);
        else puts("  not found");
        break;
        
      case PRINT_TREE:
        printTree(root);
        break;
        
      case DEL_BNODE:
        deleteBNode(&root, scanMember(NO));
        break;
    }
  } while (menu != EXIT);
  deleteTree(root);
}

Menu selectMenu(const char *menu[])
{
  int temp;
  puts("  -------------Menu------------");
  for (int i = EXIT; i <= DEL_BNODE; i++)
    printf(" | (%d) %s\n", i + 1, menu[(i + 1) % (DEL_BNODE + 1)]);
  printf("  -----------------------------\n  select menu : ");
  scanf("%d", &temp);
  return (Menu)(temp % (DEL_BNODE + 1));
}
