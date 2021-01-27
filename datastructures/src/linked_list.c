#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

List *new_list() {
    List *new = malloc(sizeof(List));
    new->first = NULL;
    return new;
}

void free_list(List *list) {
    List_Node *node = list->first;
    while (node != NULL) {
        List_Node *next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void append(List *list, int value) {
    List_Node *new = malloc(sizeof(List_Node));
    new->next = NULL;
    new->value = value;
    if (list->first == NULL) {
        list->first = new;
    } else {
        List_Node *node = list->first;
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = new;
    }
}

int delete(List *list, int value) {
    if (list->first == NULL) {
        return 0;
    }
    if (list->first->value == value) {
        List_Node *rem = list->first;
        list->first = rem->next;
        free(rem);
        return 1;
    }
    List_Node *node = list->first;
    while (node->next != NULL) {
        if (node->next->value == value) {
            List_Node *rem = node->next;
            node->next = rem->next;
            free(rem);
            return 1;
        }
        node = node->next;
    }
    return 0;
}

void print(List *list) {
    List_Node *node = list->first;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}
