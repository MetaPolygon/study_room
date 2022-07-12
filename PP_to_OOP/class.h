#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define likeClass(parameter, ...) likeClass_ctor(parameter, __VA_ARGS__)
//Variadic Macro

typedef struct _user {
    struct _user* self;
    unsigned int age;
    void (*setAge)();
    void (*printUserInfo)();
}User, *pUser;

extern pUser newUser(unsigned int age);
