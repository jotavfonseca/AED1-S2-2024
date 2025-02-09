#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void initStack(Stack *s) {
    s->top = -1;
}

void pushStack(Stack *s, int value) {
    s->data[++(s->top)] = value;
}

int popStack(Stack *s) {
    return s->data[(s->top)--];
}

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

void enqueueQueue(Queue *q, int value) {
    q->data[q->rear++] = value;
}

int dequeueQueue(Queue *q) {
    return q->data[q->front++];
}

void initPriorityQueue(PriorityQueue *pq) {
    pq->size = 0;
}

void enqueuePriorityQueue(PriorityQueue *pq, int value) {
    pq->data[pq->size++] = value;
}

int dequeuePriorityQueue(PriorityQueue *pq) {
    int maxIdx = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] > pq->data[maxIdx]) {
            maxIdx = i;
        }
    }
    int maxValue = pq->data[maxIdx];
    pq->data[maxIdx] = pq->data[--pq->size];
    return maxValue;
}

bool isPossible(int *ops, int *vals, int n) {
    Stack stack;
    Queue queue;
    PriorityQueue pq;

    initStack(&stack);
    initQueue(&queue);
    initPriorityQueue(&pq);

    bool isStack = true, isQueue = true, isPQueue = true;

    for (int i = 0; i < n; i++) {
        if (ops[i] == 1) {
            pushStack(&stack, vals[i]);
            enqueueQueue(&queue, vals[i]);
            enqueuePriorityQueue(&pq, vals[i]);
        } else {
            if (isStack) {
                if (stack.top == -1 || popStack(&stack) != vals[i]) {
                    isStack = false;
                }
            }
            if (isQueue) {
                if (queue.front == queue.rear || dequeueQueue(&queue) != vals[i]) {
                    isQueue = false;
                }
            }
            if (isPQueue) {
                if (pq.size == 0 || dequeuePriorityQueue(&pq) != vals[i]) {
                    isPQueue = false;
                }
            }
        }
    }

    if (isStack && !isQueue && !isPQueue) return printf("stack\n");
    if (!isStack && isQueue && !isPQueue) return printf("queue\n");
    if (!isStack && !isQueue && isPQueue) return printf("priority queue\n");
    if (!isStack && !isQueue && !isPQueue) return printf("impossible\n");
    return printf("not sure\n");
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ops[MAX];
        int vals[MAX];

        for (int i = 0; i < n; i++) {
            scanf("%d", &ops[i]);
            if (ops[i] == 1) {
                scanf("%d", &vals[i]);
            } else {
                scanf("%d", &vals[i]);
            }
        }

        isPossible(ops, vals, n);
    }
    return 0;
}
