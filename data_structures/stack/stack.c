#include "stack.h"

int initialize(pStack ps, int max) {
    ps->top = 0;
    if ((ps->stack = (int*)calloc(max, sizeof(int))) == NULL) {
        ps->max = 0;
        return -1;
    }
    ps->max = max;
    return 0;
}

int is_full(const pStack ps) { return ps->top == ps->max; }
int is_empty(const pStack ps) { return ps->top == 0; }

int push(pStack ps, int val) {
    if (is_full(ps))
        return -1;
    ps->stack[ps->top++] = val;
    return 0;
}

int pop(pStack ps, int *val) {
    if (is_empty(ps))
        return -1;
    *val = ps->stack[ps->top--];
    return 0;
}

void print_stack(const pStack ps) {
    for (int i = 0; i < ps->top; i++)
        printf("%d ", ps->stack[i]);
    putchar(10);
}

void del(pStack ps) {
    if (ps->stack != NULL)
        free(ps->stack);
    ps->max = ps->top = 0;
}
