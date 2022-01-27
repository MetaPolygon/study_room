
#include "linked_list.h"
int main()
{
    putchar('A');
    List list;
    
    Data data[3] = {{"",1,1.0},{"",2,2.0},{"",3,3.0}};
    
    initialize(&list);
    
    append(&list, &data[2]);
    putchar('A');
    print_list(&list);
    
}
