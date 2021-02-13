#include <stdio.h>
#include <stdlib.h>
#include "skiplist.h"

Skiplist *new_skiplist() {
    Skiplist *new = calloc(1, sizeof(Skiplist));
    new->first = calloc(1, sizeof(Skiplist_Node **));
    new->first[0] = NULL;
    new->height = 0;
    return new;
}

void free_node(Skiplist_Node *node) {
    if (node->lists[0] != NULL) {
        free_node(node->lists[0]);
    }
    free(node->lists);
    free(node);
}

void free_skiplist(Skiplist *list) {
    if (list->first != NULL && list->first[0] != NULL) {    
        free_node(list->first[0]);
        free(list->first);
    }
    free(list);
}

void _skiplist_print(Skiplist_Node *node) {
    printf("%d ", node->value);
    if (node->lists[0] != NULL) {
        _skiplist_print(node->lists[0]);
    }
}

void skiplist_print(Skiplist *list) {
    if (list->first != NULL && list->first[0] != NULL) {
        _skiplist_print(list->first[0]);
    }
    printf("\n");
}

int _insert_node(Skiplist_Node *new, int height, Skiplist_Node **current) {
    if (height < 0) return 0;
    Skiplist_Node *next = current[height];
    if (next != NULL) {
        if (new->value == next->value) return 1;
        if (new->value > next->value) {
            return _insert_node(new, height, current[height]->lists);
        }
    }
    int duplicate = _insert_node(new, height - 1, current);
    if (!duplicate) {
        new->lists[height] = next;
        current[height] = new;
    }
    return duplicate;
}

void skiplist_insert(Skiplist *list, int key) {
    //create new node
    Skiplist_Node *new = calloc(1, sizeof(Skiplist_Node));
    new->value = key;
    new->height = 1;
    //random new height
    int r;
    while ((r = rand() % 2)) {
        new->height++;
    }
    new->lists = calloc(new->height + 1, sizeof(Skiplist_Node **));
    int height_diff = new->height - list->height;
    if (height_diff > 0) {
        //increase 'first' vector to the new max size
        list->first = realloc(list->first, (new->height + 1) * sizeof(Skiplist_Node **));
        //set new 'first' vector items to NULL
        for (int i = list->height + 1; i <= new->height; i++) {
            list->first[i] = NULL;
        }
        list->height = new->height;
    }
    //insert new node into each linked list, starting from the top
    int duplicate = _insert_node(new, new->height, list->first);
    //reverse changes in case of duplicate
    if (duplicate) {
        free(new->lists);
        free(new);
        if (height_diff > 0) {
            list->height -= height_diff;
            list->first = realloc(list->first, (list->height + 1) * sizeof(Skiplist_Node **));
        }
    }
}

void _delete_node(Skiplist_Node **current, int height, int key) {
    if (height < 0) return;
    Skiplist_Node *next = current[height];
    if (next != NULL) {
        if (next->value == key) {
            current[height] = next->lists[height];
            if (height == 0) {
                free(next->lists);
                free(next);
                return;
            }
        }
        else if (next->value < key) {
            return _delete_node(next->lists, height, key);
        }
    }
    _delete_node(current, height - 1, key);
}

void skiplist_remove(Skiplist *list, int key) {
    if (*list->first != NULL) {
        _delete_node(list->first, list->height, key);
    }
}

int _search_node(Skiplist_Node **current, int height, int key) {
    if (height < 0) return 0;
    Skiplist_Node *next = current[height];
    if (next != NULL) {
        if (next->value == key) {
            return 1;
        }
        if (next->value < key) {
            return _search_node(next->lists, height, key);
        }
    }
    return _search_node(current, height - 1, key);
}

int skiplist_search(Skiplist *list, int key) {
    if (*list->first != NULL) {
        return _search_node(list->first, list->height, key);
    }
    return 0;
}
