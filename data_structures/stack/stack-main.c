#include "stack.h"
#define SIZE 5

enum __eMenu
{
  DELETE_STACK,
  PUSH,
  POP,
  SEARCH,
  PRINT_STACK,
};
typedef enum __eMenu Menu;

Menu selectMenu(const char *[]);

int main() {
  const char* menu_list[] = {
    "| Delete Stack          |",
    "| Push                  |",	
    "| Pop                   |",
    "| Search                |",
    "| Print Stack           |",
  };
  Stack s;
  initialize(&s, SIZE);
  int menu, temp;
  do {
    switch (menu = selectMenu(menu_list)) {
      case PUSH:
        if (isFull(&s) != 1) push(&s, valInput());
        else puts("  Stack Full !");
        break;
      case POP:
        if (isEmpty(&s) != 1) pop(&s, &temp);
        else puts("  Stack Empty !");
        break;
      case SEARCH:
        if ((temp = search(&s, valInput())) != -1)
          printf("  Search value in index : %d\n", temp);
        else puts("  not in");
        break;
      case PRINT_STACK:
        printStack(&s);
        break;
      case DELETE_STACK:
        deleteStack(&s);
        break;
    } 
  } while (menu != DELETE_STACK);
}

Menu selectMenu(const char *menu[])
{
  puts("  -------------Menu------------");
  for (int i = DELETE_STACK; i <= PRINT_STACK; i++)    
    printf(" | (%d) %s\n", i + 1, menu[(i + 1) % (PRINT_STACK + 1)]);
  printf("  -----------------------------\n  select menu : ");
  int temp;
  scanf("%d", &temp);
  return (Menu)(temp % (PRINT_STACK + 1));
}
