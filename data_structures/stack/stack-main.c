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
  int menu, pop_value;
  do {
    switch (menu = selectMenu(menu_list)) {
      case PUSH:
        push(&s, valInput());
        break;
      case POP:
        pop(&s, &pop_value);
        break;
      case SEARCH:
        search(&s, valInput());
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
