#include <stdio.h>
#include <stdlib.h>
typedef struct __stack {
    int top, max;
    int *stack;
}Stack, *pStack;

int initialize(pStack s, int max);
int is_full(const pStack s);
int is_empty(const pStack s);
int push(pStack s, int val);
int pop(pStack s, int *val);
void print_stack(const pStack s);
void del_stack(pStack s);
