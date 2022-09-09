#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _user {
    char *name;
    unsigned int age;
}User, *pUser;

void setName(pUser user, char* name)
{
    char* temp = malloc(sizeof(char) * strlen(name));
    strcpy(temp, name);
    user->name = temp;
}

void setAge(pUser user, unsigned int age)
{
    user->age = age;
}

void printUserInfo(pUser user)
{
    printf("name : %s\n", user->name);
    printf("age : %u", user->age);
}


int main()
{
    User user;
    setName(&user, "Mike");
    setAge(&user, 33);
    printUserInfo(&user);
    free(user.name);
}
