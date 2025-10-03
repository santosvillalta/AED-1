#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_X 100

// --- Estrutura da Pilha (Stack - LIFO) ---
typedef struct {
    int items[MAX_N];
    int topo;
} Stack;

void stack_init(Stack *s) {
    s->topo = -1;
}
void stack_push(Stack *s, int x) {
    if (s->topo < MAX_N - 1) {
        s->items[++s->topo] = x;
    }
}
int stack_top(Stack *s) {
    if (s->topo != -1) {
        return s->items[s->topo];
    }
    return -1;
}
int stack_pop(Stack *s) {
    if (s->topo != -1) {
        return s->items[s->topo--];
    }
    return -1;
}
int stack_empty(Stack *s) {
    return s->topo == -1;
}

// --- Estrutura da Fila (Queue - FIFO) ---
typedef struct {
    int items[MAX_N];
    int frente;
    int fim;
    int count;
} Queue;

void queue_init(Queue *q) {
    q->frente = 0;
    q->fim = -1;
    q->count = 0;
}
void queue_push(Queue *q, int x) {
    if (q->count < MAX_N) {
        q->fim = (q->fim + 1) % MAX_N;
        q->items[q->fim] = x;
        q->count++;
    }
}
int queue_front(Queue *q) {
    if (q->count > 0) {
        return q->items[q->frente];
    }
    return -1;
}
int queue_pop(Queue *q) {
    if (q->count > 0) {
        int x = q->items[q->frente];
        q->frente = (q->frente + 1) % MAX_N;
        q->count--;
        return x;
    }
    return -1;
}
int queue_empty(Queue *q) {
    return q->count == 0;
}

// --- Funções Auxiliares para Fila de Prioridade ---
int compare_ints(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); 
}

// --- Estrutura da Fila de Prioridade (Priority Queue) ---
