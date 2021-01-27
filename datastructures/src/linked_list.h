#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct list_node {
    struct list_node *next;
    int value;
} List_Node;

typedef struct {
    List_Node *first;
} List;

List *new_list();

void free_list(List *list);

void append(List *list, int value);

int delete(List *list, int value);

void print(List *list);

#endif
