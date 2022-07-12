#include "class.h"

int main()
{
    pUser user1 = newUser(11);
    pUser user2 = newUser(22);
    pUser user3 = newUser(33);
    
    user1->printUserInfo();
    printf("%p\n", user1);
    user2->printUserInfo();
    printf("%p\n", user2);
    user3->printUserInfo();
    printf("%p\n", user3);
}
