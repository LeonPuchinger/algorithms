#include "avl_tree.h"
#include <stdlib.h>
#include <stdio.h>

Avl_Tree *new_avl_tree() {
    Avl_Tree *new = calloc(1, sizeof(Avl_Tree));
    new->root = NULL;
    return new;
}

Avl_Tree_Node *new_node(int value) {
    Avl_Tree_Node *new = calloc(1, sizeof(Avl_Tree_Node));
    new->left = NULL;
    new->right = NULL;
    new->height = 0;
    new->value = value;
    return new;
}

void free_nodes(Avl_Tree_Node *node) {
    if (node->left != NULL) free_nodes(node->left);
    if (node->right != NULL) free_nodes(node->right);
    free(node);
}

void free_avl_tree(Avl_Tree *tree) {
    if (tree->root != NULL) free_nodes(tree->root);
    free(tree);
}

void _avl_tree_inorder(Avl_Tree_Node *node) {
    if (node != NULL) {
        _avl_tree_inorder(node->left);
        printf("%d ", node->value);
        _avl_tree_inorder(node->right);
    }
}

void avl_tree_inorder(Avl_Tree *tree) {
    _avl_tree_inorder(tree->root);
    printf("\n");
}

int get_next_height(Avl_Tree_Node *node) {
    if (node == 0) return 0;
    return node->height + 1;
}

void update_height(Avl_Tree_Node *node) {
    int left = get_next_height(node->left);
    int right = get_next_height(node->right);
    if (right > left) left = right;
    node->height = left;
}

Avl_Tree_Node *rotate_left(Avl_Tree_Node *node, Avl_Tree_Node **predecessor) {
    Avl_Tree_Node *right = node->right;
    node->right = right->left;
    right->left = node;
    *predecessor = right;
    update_height(node);
    update_height(right);
    return right;
}

Avl_Tree_Node *rotate_right(Avl_Tree_Node *node, Avl_Tree_Node **predecessor) {
    Avl_Tree_Node *left = node->left;
    node->left = left->right;
    left->right = node;
    *predecessor = left;
    update_height(node);
    update_height(left);
    return left;
}

void checkRotation(Avl_Tree_Node *node, Avl_Tree_Node **predecessor) {
    int diff = get_next_height(node->left) - get_next_height(node->right);
    if (diff == 2) { //left tree too high
        if (get_next_height(node->left->right) > get_next_height(node->left->left)) {
            node->left = rotate_left(node->left, &(node->left));
        }
        rotate_right(node, predecessor);
    } else if(diff == -2) { //right tree too high
        if (get_next_height(node->right->left) > get_next_height(node->right->right)) {
            node->right = rotate_right(node->right, &(node->right));
        }
        rotate_left(node, predecessor);
    }
}

void _avl_tree_insert(Avl_Tree_Node *node, Avl_Tree_Node **predecessor, Avl_Tree_Node *new) {
    if (new->value < node->value) {
        if (node->left != NULL) {
            _avl_tree_insert(node->left, &(node->left), new);
            update_height(node);
            checkRotation(node, predecessor);
            return;
        }
        node->left = new;
        if (node->height < 1) node->height = 1;
        return;
    }
    if (new->value > node->value) {
        if (node->right != NULL) {
            _avl_tree_insert(node->right, &(node->right), new);
            update_height(node);
            checkRotation(node, predecessor);
            return;
        }
        node->right = new;
        if (node->height < 1) node->height = 1;
        return;
    }
}

void avl_tree_insert(Avl_Tree *tree, int value) {
    Avl_Tree_Node *new = new_node(value);
    if (tree->root == NULL) {
        tree->root = new;
        return;
    }
    _avl_tree_insert(tree->root, &(tree->root), new);
}

int _avl_tree_remove(Avl_Tree_Node *node, Avl_Tree_Node **predecessor, int value) {
    if (value < node->value) {
        if (node->left != NULL) {
            int success = _avl_tree_remove(node->left, &(node->left), value);
            update_height(node);
            checkRotation(node, predecessor);
            return success;
        }
        return 0;
    }
    if (value > node->value) {
        if (node->right != NULL) {
            int success = _avl_tree_remove(node->right, &(node->right), value);
            update_height(node);
            checkRotation(node, predecessor);
            return success;
        }
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        *predecessor = NULL;
        free(node);
        return 1;
    }
    if (node->left != NULL && node->right == NULL) {
        *predecessor = node->left;
        free(node);
        return 1;
    }
    if (node->left == NULL && node->right != NULL) {
        *predecessor = node->right;
        free(node);
        return 1;
    }
    
    Avl_Tree_Node *inorder = node->right;
    Avl_Tree_Node **inorder_predecessor = &(node->right);
    while (inorder->left != NULL) {
        inorder_predecessor = &(inorder->left);
        inorder = inorder->left;
    }

    inorder->left = node->left;
    if (inorder != node->right) {
        inorder->right = node->right;
        *inorder_predecessor = NULL;
    }
    *predecessor = inorder;
    free(node);
    update_height(inorder);
    checkRotation(inorder, predecessor);
    return 1;
}

int avl_tree_remove(Avl_Tree *tree, int value) {
    if (tree->root == NULL) return 0;
    return _avl_tree_remove(tree->root, &(tree->root), value);
}
