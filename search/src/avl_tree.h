#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct _avl_tree_node {
    int value, height;
    struct _avl_tree_node *left, *right;
} Avl_Tree_Node;

typedef struct {
    Avl_Tree_Node *root;
} Avl_Tree;

Avl_Tree *new_avl_tree();

void free_avl_tree(Avl_Tree *tree);

void avl_tree_inorder(Avl_Tree *tree);

void avl_tree_insert(Avl_Tree *tree, int value);

int avl_tree_remove(Avl_Tree* tree, int value);

#endif
