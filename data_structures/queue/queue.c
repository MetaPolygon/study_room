#include "queue.h"

int initialize(pQueue q, int max) {
    q->cnt = q->front = q->rear = 0;
    if ((q->queue = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int is_full(const pQueue q) { return q->cnt == q->max; }
int is_empty(const pQueue q) { return q->cnt == 0; }

int en_queue(pQueue q, int val) {
    if (is_full(q)) return -1;
    else {
        q->cnt++;
        q->queue[q->rear++] = val;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

int de_queue(pQueue q, int *val) {
    if (is_empty(q)) return -1;
    else {
        q->cnt--;
        *val = q->queue[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

void print_queue(const pQueue q) {
    for (int i = 0; i < q->cnt; i++)
        printf("%d ", q->queue[(i + q->front) % q->max]);
    putchar(10);
}

void del_stack(pQueue q) {
    if (q->queue != NULL)
        free(q->queue);
    q->max = q->cnt = q->front = q->rear = 0; 
}
