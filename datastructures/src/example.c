#include "stack.h"
#include <stdio.h>

int main() {
    Stack *stack = new_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("popped %d from stack\n", pop(stack));
    printf("%d is now on top of stack\n", peek(stack));
    printf("stack is of size %d now\n", size(stack));
    free_stack(stack);
}
