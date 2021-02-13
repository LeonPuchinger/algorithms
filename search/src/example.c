#include "bin_search_tree.h"
#include <stdio.h>

int main() {
    Bin_Tree *tree = new_bin_tree();
    bin_tree_insert(tree, 2);
    bin_tree_insert(tree, 3);
    bin_tree_insert(tree, 1);
    bin_tree_preorder(tree);
    bin_tree_inorder(tree);
    bin_tree_postorder(tree);
    bin_tree_remove(tree, 1);
    bin_tree_inorder(tree);
    free_bin_tree(tree);    
}
