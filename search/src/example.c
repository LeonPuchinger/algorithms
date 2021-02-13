#include "bin_search_tree.h"
#include <stdio.h>

int main() {
    Bin_Tree *tree = new_bin_tree();
    insert_bin_tree(tree, 2);
    insert_bin_tree(tree, 3);
    insert_bin_tree(tree, 1);
    print_preorder(tree);
    print_inorder(tree);
    print_postorder(tree);
    remove_bin_tree(tree, 1);
    print_inorder(tree);
    free_bin_tree(tree);    
}
