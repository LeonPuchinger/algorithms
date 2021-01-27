#include "stack.h"
#include "queue.h"
#include "linked_list.h"
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

    Queue *queue = new_queue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("dequeued %d from queue\n", dequeue(queue));
    free_queue(queue);

    List *list = new_list();
    append(list, 1);
    append(list, 2);
    append(list, 3);
    printf("the list is now: ");
    print(list);
    int res = delete(list, 2);
    if (res) {
        printf("2 was removed from the list\n");
    } else {
        printf("2 was not found and could not be removed from the list\n");
    }
    printf("the list is now: ");
    print(list);
    free_list(list);
}
