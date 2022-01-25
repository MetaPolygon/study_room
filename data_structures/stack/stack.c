#include "stack.h"

int initialize(pStack s, int max) {
    s->top = 0;
    if ((s->stack = (int*)calloc(max, sizeof(int))) == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int is_full(const pStack s) { return s->top == s->max; }
int is_empty(const pStack s) { return s->top == 0; }

int push(pStack s, int val) {
    if (is_full(s)) return -1;
    s->stack[s->top++] = val;
    return 0;
}

int pop(pStack s, int *val) {
    if (is_empty(s)) return -1;
    *val = s->stack[s->top--];
    return 0;
}

int search(const pStack s, int val) {
    for (int i = s->top - 1; i >= 0; i--)
        if (s->stack[i] == val)
            return i;
    return -1;
}

void print_stack(const pStack s) {
    for (int i = 0; i < s->top; i++)
        printf("%d ", s->stack[i]);
    putchar(10);
}

void del_stack(pStack s) {
    if (s->stack != NULL)
        free(s->stack);
    s->max = s->top = 0;
}
