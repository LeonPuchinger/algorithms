#ifndef QUEUE_H
#define QUEUE_H

typedef struct _node {
    struct _node *next;
    int value;
} Node;

typedef struct {
    Node *head, *tail;
} Queue;

Queue *new_queue();

void free_queue(Queue *queue);

void enqueue(Queue *queue, int i);

int dequeue(Queue *queue);

#endif
