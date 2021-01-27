#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_node {
    struct queue_node *next;
    int value;
} Queue_Node;

typedef struct {
    Queue_Node *head, *tail;
} Queue;

Queue *new_queue();

void free_queue(Queue *queue);

void enqueue(Queue *queue, int i);

int dequeue(Queue *queue);

#endif
