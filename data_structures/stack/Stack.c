#include "stack.h"

static int initialize(int max);
static int isFull();
static int isEmpty();
static int push(int val);
static int pop(int *val);
static void printStack();
static void delStack();

static Stack this = {
    0, 0,
    NULL,
    initialize,
    isFull,
    isEmpty,
    push,
    pop,
    printStack,
    delStack
};

pStack stackCtor(int n) {
    if (initialize(n) == -1) {
        puts("lack of memory!");
        return NULL;
    }
    return &this;
}

static int initialize(int max) {
    this.top = 0;
    if ((this.stack = (int*)calloc(max, sizeof(int))) == NULL) {
        this.max = 0;
        return -1;
    }
    this.max = max;
    return 0;
}

static int isFull() { return this.top == this.max; }
static int isEmpty() { return this.top == 0; }

static int push(int val) {
    if (isFull()) return -1;
    this.stack[this.top++] = val;
    return 0;
}

static int pop(int *val) {
    if (isEmpty()) return -1;
    *val = this.stack[this.top--];
    return 0;
}

static void printStack() {
    for (int i = 0; i < this.top; i++)
        printf("%d ", this.stack[i]);
    putchar(10);
}

static void delStack() {
    if (this.stack != NULL)
        free(this.stack);
    this.max = this.top = 0;
}
