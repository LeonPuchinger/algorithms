#ifndef SKIPLIST_H
#define SKIPLIST_H

typedef struct _skiplist_node {
    struct _skiplist_node **lists;
    int value, height;
} Skiplist_Node;

typedef struct {
    Skiplist_Node **first;
    int height;
} Skiplist;

Skiplist *new_skiplist();

void free_skiplist(Skiplist *list);

void skiplist_print(Skiplist *list);

void skiplist_insert(Skiplist *list, int key);

void skiplist_remove(Skiplist *list, int key);

int skiplist_search(Skiplist *list, int key);

#endif
