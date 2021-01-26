#include "stack.h"
#include <stdlib.h>

#define BLOCK_SIZE 10

Stack *new_stack() {
    Stack *s = calloc(1, sizeof(Stack));
    s->stack = calloc(BLOCK_SIZE, sizeof(int));
    s->alloc_size = BLOCK_SIZE;
    s->n = 0;
    return s;
}

void free_stack(Stack *s) {
    free(s->stack);
    free(s);
}

int pop(Stack *s) {
    s->n--;
    return s->stack[s->n];
}

void push(Stack *s, int v) {
    if (s->alloc_size == s->n) {
        s->alloc_size += BLOCK_SIZE;
        s->stack = realloc(s->stack, s->alloc_size * sizeof(int));
    }
    s->stack[s->n] = v;
    s->n++;
}

int peek(Stack *s) {
    return s->stack[s->n-1];
}

int size(Stack *s) {
    return s->n;
}
