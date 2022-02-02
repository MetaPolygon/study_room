#include "linked-list.h"

enum __eMenu
{
  EXIT,
  APPEND,
  INSERT,
  SEARCH,
  PRINT_LIST,
  DEL_NODE,
};
typedef enum __eMenu Menu;

Menu selectMenu(const char *[]);

int main()
{
  const char* menu_list[] = {
    "| Exit                  |",
    "| Append Node           |",
    "| Insert Node           |",	
    "| Search Node           |",
    "| All Print Node Info   |",
    "| Delete Node           |",
  };
  Menu menu;
  List list;
  pMember member;
  initialize(&list, NULL);
  do {
    switch(menu = selectMenu(menu_list)) {
      case APPEND:
        member = scanMember(ALL);
        if (appendNode(&list, list.tail, member) == -1)
          puts("  fail append node");
        break;
      case INSERT:
        puts("  [input search no]");
        member = scanMember(ALL);
        if (searchNode(&list, member) != NULL) {
          member = scanMember(ALL);
          if (insertNode(&list, member) == -1)
            puts("  fail insert node");
        }
        break;
      case SEARCH:
        if (searchNode(&list, scanMember(NO)) != NULL)
          printNode(list.select);
        break;
      case PRINT_LIST:
        printList(&list);
        break;
      case DEL_NODE:
        if (searchNode(&list, scanMember(NO)) != NULL)
          deleteNode(&list);
        break;
      case EXIT:
        deleteList(&list);
        break;
    }
  } while (menu != EXIT);
}

Menu selectMenu(const char *menu[])
{
  puts("  -------------Menu------------");
  for (int i = EXIT; i <= DEL_NODE; i++)    
    printf(" | (%d) %s\n", i + 1, menu[(i + 1) % (DEL_NODE + 1)]);
  printf("  -----------------------------\n  select menu : ");
  int temp;
  scanf("%d", &temp);
  return (Menu)(temp % (DEL_NODE + 1));
}
