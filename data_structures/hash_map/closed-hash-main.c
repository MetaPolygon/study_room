#include "closed-hash.h"
#define SIZE 13
enum __eMenu
{
  EXIT,
  APPEND,
  SEARCH,
  PRINT_TABLE,
  DEL_BUCKET,
};
typedef enum __eMenu Menu;

Menu selectMenu(const char *[]);

int main()
{
  const char* menu_list[] = {
    "| Exit                  |",
    "| Append Bucket         |",	
    "| Search Bucket         |",
    "| All Print Bucket Info |",
    "| Delete Bucket         |",
  };
  Menu menu;
  ClosedHash hash_map;
  initialize(&hash_map, SIZE);
  pBucket temp;
  pMember member;
  do {
    switch (menu = selectMenu(menu_list)) {
      case APPEND:
        member = scanMember(ALL);
        if (menu == APPEND && appendData(&hash_map, member) == -1)
          puts("  fail append node");
        break;
        
      case SEARCH:
        if ((temp = searchBucket(&hash_map, scanMember(NO))) != NULL)
          printData(temp);
        else puts("  not found");
        break;
        
      case PRINT_TABLE:
        printTable(&hash_map);
        break;
        
      case DEL_BUCKET:
        deleteData(searchBucket(&hash_map, scanMember(NO)), DELETED)
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
  for (int i = EXIT; i <= DEL_BUCKET; i++)    
    printf(" | (%d) %s\n", i + 1, menu[(i + 1) % (DEL_BUCKET + 1)]);
  printf("  -----------------------------\n  select menu : ");
  int temp;
  scanf("%d", &temp);
  return (Menu)(temp % (DEL_BUCKET + 1));
}
