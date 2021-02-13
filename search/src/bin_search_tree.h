#ifndef BIN_SEARCH_TREE_H
#define BIN_SEARCH_TREE_H

typedef struct _bin_tree_node {
    struct _bin_tree_node *right, *left;
    int value;
} Bin_Tree_Node;

typedef struct {
    Bin_Tree_Node *root;
} Bin_Tree;

Bin_Tree *new_bin_tree();

void free_bin_tree(Bin_Tree *tree);

void bin_tree_preorder(Bin_Tree *tree);

void bin_tree_inorder(Bin_Tree *tree);

void bin_tree_postorder(Bin_Tree *tree);

void bin_tree_insert(Bin_Tree *tree, int value);

int bin_tree_remove(Bin_Tree *tree, int value);

#endif
