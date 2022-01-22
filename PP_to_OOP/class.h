#include <stdio.h>
#define likeClass(parameter, ...) likeClass_ctor(parameter, __VA_ARGS__)
//Variadic Macro

typedef struct __likeClass{
    int num;
    void (*constructor)();
    void (*printInfo)();
}likeClass, *pLikeClass;

extern pLikeClass likeClass_ctor(int, ...);
