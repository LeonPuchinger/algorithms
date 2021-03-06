#include "bin_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

Bin_Tree *new_bin_tree() {
    Bin_Tree *new = malloc(sizeof(Bin_Tree));
    new->root = NULL;
    return new;
}

void _free_bin_tree(Bin_Tree_Node *node) {
    if (node->left != NULL) {
        _free_bin_tree(node->left);
    }
    if (node->right != NULL) {
        _free_bin_tree(node->right);
    }
    free(node);
}

void free_bin_tree(Bin_Tree *tree) {
    if (tree->root != NULL) {
        _free_bin_tree(tree->root);
    }
    free(tree);
}

void _bin_tree_preorder(Bin_Tree_Node *node) {
    printf("%d ", node->value);
    if (node->left != NULL) {
        _bin_tree_preorder(node->left);
    }
    if (node->right != NULL) {
        _bin_tree_preorder(node->right);
    }
}

void bin_tree_preorder(Bin_Tree *tree) {
    if (tree->root != NULL) {
        _bin_tree_preorder(tree->root);
    }
    printf("\n");
}

void _bin_tree_inorder(Bin_Tree_Node *node) {
    if (node->left != NULL) {
        _bin_tree_inorder(node->left);
    }
    printf("%d ", node->value);
    if (node->right != NULL) {
        _bin_tree_inorder(node->right);
    }
}

void bin_tree_inorder(Bin_Tree *tree) {
    if (tree->root != NULL) {
        _bin_tree_inorder(tree->root);
    }
    printf("\n");
}

void _bin_tree_postorder(Bin_Tree_Node *node) {
    if (node->left != NULL) {
        _bin_tree_postorder(node->left);
    }
    if (node->right != NULL) {
        _bin_tree_postorder(node->right);
    }
    printf("%d ", node->value);
}

void bin_tree_postorder(Bin_Tree *tree) {
    if (tree->root != NULL) {
        _bin_tree_postorder(tree->root);
    }
    printf("\n");
}

void _bin_tree_insert(Bin_Tree_Node *root, Bin_Tree_Node *new) {
    if (new->value >= root->value) {
        if (root->right != NULL) {
            return _bin_tree_insert(root->right, new);
        }
        root->right = new;
    } else {
        if (root->left != NULL) {
            return _bin_tree_insert(root->left, new);
        }
        root->left = new;
    }
}

void bin_tree_insert(Bin_Tree *tree, int value) {
    Bin_Tree_Node *new = malloc(sizeof(Bin_Tree_Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    if (tree->root == NULL) {
        tree->root = new;
    } else {
        _bin_tree_insert(tree->root, new);
    }
}

Bin_Tree_Node *inorder_successor(Bin_Tree_Node *node) {
    if (node->left != NULL) {
        return inorder_successor(node->left);
    }
    return node;
}

Bin_Tree_Node *_remove_node(Bin_Tree_Node *node) {
    if (node->left == NULL && node->right == NULL) {
        free(node);
        return NULL;
    }
    if (node->left != NULL && node->right == NULL) {
        Bin_Tree_Node *left = node->left;
        free(node);
        return left;
    }
    if (node->left == NULL && node->right != NULL) {
        Bin_Tree_Node *right = node->right;
        free(node);
        return right;
    }
    Bin_Tree_Node *inorder = inorder_successor(node->right);
    node->value = inorder->value;
    node->left = _remove_node(inorder);
    return node;
}

int _bin_tree_remove(Bin_Tree_Node *node, Bin_Tree_Node **predecessor, int value) {
    if (node == NULL) return 0;
    if (node->value == value) {
        *predecessor = _remove_node(node);
        return 1;
    } else {
        if (value < node->value) {
            return _bin_tree_remove(node->left, &(node->left), value);
        } else {
            return _bin_tree_remove(node->right, &(node->right), value);
        }
    }
}

int bin_tree_remove(Bin_Tree *tree, int value) {
    if (tree->root != NULL) {
        return _bin_tree_remove(tree->root, &(tree->root), value);
    }
    return 0;   
}
