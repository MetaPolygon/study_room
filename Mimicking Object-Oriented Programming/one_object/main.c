#include "class.h"

int main()
{
    pUser user = newUser("mike", 26, 178.4, 72.6);
    user->printUserInfo();
    free(user);
}
