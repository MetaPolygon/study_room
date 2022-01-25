#include <stdio.h>
#include <stdlib.h>

typedef struct __queue {
    int max, cnt;
    int front, rear;
    int *queue;
}Queue, *pQueue;

int initialize(pQueue q, int max);
int is_full(const pQueue q);
int is_empty(const pQueue q);
int en_queue(pQueue q, int val);
int de_queue(pQueue q, int *val);
int search(const pQueue q, int val);
void print_queue(const pQueue q);
void del_stack(pQueue q);
