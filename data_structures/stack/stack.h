#include <stdio.h>
#include <stdlib.h>

struct __Stack
{
  int top, max;
  int *stack;
};
typedef struct __Stack Stack, *pStack;

int initialize(pStack s, int max);
int valInput();
int isFull(const pStack s);
int isEmpty(const pStack s);
int push(pStack s, int val);
int pop(pStack s, int *val);
int search(const pStack s, int val);
void printStack(const pStack s);
void deleteStack(pStack s);
