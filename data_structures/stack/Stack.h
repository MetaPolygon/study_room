#include <stdio.h>
#include <stdlib.h>
#define Stack(size) stackCtor(size);

typedef struct __stack {
    int top, max;
    int *stack;
    int (*initialize)(int max);
    int (*isFull)();
    int (*isEmpty)();
    int (*push)(int val);
    int (*pop)(int *val);
    void (*printStack)();
    void (*delStack)();
}Stack, *pStack;

extern pStack stackCtor(int size);
