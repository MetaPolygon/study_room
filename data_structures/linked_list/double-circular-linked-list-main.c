   
#include "double-circular-linked-list.h"

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
  int menu;
  DList list;
  pMember member;
  initialize(&list);
  do {
    switch(menu = selectMenu(menu_list)) {
      case APPEND:
      case INSERT: 
        member = scanMember(ALL);
        if (menu == APPEND && appendDNode(&list, list.head->prev, member) == -1)
          puts("  fail append node");
        else if (menu == INSERT) {
          puts("  [input index]");
          if (searchDNode(&list, member) != NULL) {
            member = scanMember(ALL);
            if (insertDNode(&list, member) == -1)
              puts("  fail insert node");
          }
        }
        break;
      case SEARCH:
        if (searchDNode(&list, scanMember(NO)) != NULL)
          printDNode(&list);
        break;
      case PRINT_LIST:
        printDList(&list);
        break;
      case DEL_NODE:
        if (searchDNode(&list, scanMember(NO)) != NULL)
          deleteDNode(&list);
        break;
      case EXIT:
        deleteDList(&list);
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
