#include <stdio.h>

typedef struct __likeClass{
    int (*test)();
}likeClass;

extern likeClass *set();
