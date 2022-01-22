#include <stdio.h>
#include <stdlib.h>
typedef struct __stack {
    int top, max;
    int *stack;
}Stack, *pStack;

int initialize(pStack ps, int max);
int is_full(const pStack ps);
int is_empty(const pStack ps);
int push(pStack ps, int val);
int pop(pStack ps, int *val);
void print_stack(const pStack ps);
void del_stack(pStack ps);
