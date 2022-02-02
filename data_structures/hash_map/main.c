#include "hash-map.h"
#define SIZE 13
enum __eMenu
{
  EXIT,
  APPEND,
  SEARCH,
  PRINT_TABLE,
  DEL_NODE,
};
typedef enum __eMenu Menu;

Menu selectMenu(const char *[]);

int main()
{
  const char* menu_list[] = {
    "| Exit                  |",
    "| Append Node           |",	
    "| Search Node           |",
    "| All Print Node Info   |",
    "| Delete Node           |",
  };
  Menu menu;
  ChainHash hash_map;
  initialize(&hash_map, SIZE);
  pNode temp;
  pMember member;
  do {
    switch (menu = selectMenu(menu_list)) {
      case APPEND:
        member = scanMember(ALL);
        if (menu == APPEND && appendNode(&hash_map, member) == -1)
          puts("  fail append node");
        break;
        
      case SEARCH:
        if ((temp = searchNode(&hash_map, scanMember(NO))) != NULL)
          printNode(temp);
        else puts("  not found");
        break;
        
      case PRINT_TABLE:
        printTable(&hash_map);
        break;
        
      case DEL_NODE:
        deleteNode(&hash_map, scanMember(NO));
        break;
        
      case EXIT:
        deleteTable(&hash_map);
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
