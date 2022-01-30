#include "linked-list.h"

enum __eMenu
{
  EXIT,
  APPEND,
  INSERT,
  SEARCH,
  PRINT_LIST,
  DEL_NODE,
  DEL_LIST,
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
    "| Delete List           |",
  };
  int menu;
  List list;
  pMember member;
  initialize(&list, NULL);
  do {
    switch(menu = selectMenu(menu_list)) {
      case APPEND:
      case INSERT: 
        member = scanMember(ALL);
        if (menu == APPEND && appendNode(&list, member) == -1)
          puts("fail append node");
        else if (menu == INSERT) {
          int idx;
          printf("input index : ");
          scanf("%d", &idx);
          if (insertNode(&list, member, idx) == -1)
            puts("fail insert node");
        };
        break;
      case SEARCH:
        if (searchNode(&list, scanMember(NO)) != NULL)
          printNode(list.select);
        else puts("No matching search node");
        break;
      case PRINT_LIST:
        printList(&list);
        break;
      case DEL_NODE:
        searchNode(&list, scanMember(NO));
        deleteNode(&list);
        break;
      case DEL_LIST: case EXIT:
        deleteList(&list);
        break;
    }
  } while (menu != EXIT);
}

Menu selectMenu(const char *menu[])
{
  puts("  -------------Menu------------");
  for (int i = EXIT; i <= DEL_LIST; i++)    
    printf(" | (%d) %s\n", i + 1, menu[(i + 1) % (DEL_LIST + 1)]);
  printf("  -----------------------------\n  select menu : ");
  int temp;
  scanf("%d", &temp);
  return (Menu)(temp % (DEL_LIST + 1));
}
