#include "queue.h"
#include <stdlib.h>

Queue *new_queue() {
    Queue *q = calloc(1, sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void free_queue(Queue *queue) {
    if (queue->head != NULL) {
        queue->tail->next = NULL;
        Queue_Node *n = queue->head;
        while (n != NULL) {
            Queue_Node *next = n->next;
            free(n);
            n = next;
        }
    }
    free(queue);
}

void _enqueue(Queue *queue, Queue_Node *node) {
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail= node;
        node->next = node;
    } else {
        node->next = queue->head;
        queue->tail->next = node;
        queue->tail = node;
    }
}

void enqueue(Queue *queue, int i) {
    Queue_Node *n = calloc(1, sizeof(Queue_Node));
    n->value = i;
    _enqueue(queue, n);
}

Queue_Node *_dequeue(Queue *queue) {
    Queue_Node *n = queue->head;
    if (queue->head != queue->tail) {
        queue->tail->next = n->next;
        queue->head = n->next;
    } else {
        queue->head = NULL;
        queue->tail = NULL;
    }
    return n;
}

int dequeue(Queue *queue) {
    Queue_Node *n = _dequeue(queue);
    int i;
    if (n == NULL) i = 0;
    else i = n->value;
    free(n);
    return i;
}
