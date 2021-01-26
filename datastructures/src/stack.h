#ifndef STACK_H
#define STACK_H

typedef struct {
    int *stack, alloc_size, n;
} Stack;

Stack *new_stack();

void free_stack(Stack *s);

void push(Stack *s, int v);

int pop(Stack *s);

int peek(Stack *s);

int size(Stack *s);

#endif
