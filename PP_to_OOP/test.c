#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _user{
	char *name;
}User, *pUser;

void setName(pUser user, char* name)
{
    char* temp = malloc(sizeof(char) * strlen(name));
    strcpy(temp, name);
    user->name = temp;
}

int main()
{
    User user;
    setName(&user, "Mike");
    printf("%s",user.name);
    free(user.name);
}
