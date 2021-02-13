#include "bin_search_tree.h"
#include "avl_tree.h"
#include "skiplist.h"
#include <stdio.h>

int main() {
    Bin_Tree *bin_tree = new_bin_tree();
    bin_tree_insert(bin_tree, 2);
    bin_tree_insert(bin_tree, 3);
    bin_tree_insert(bin_tree, 1);
    bin_tree_preorder(bin_tree);
    bin_tree_inorder(bin_tree);
    bin_tree_postorder(bin_tree);
    bin_tree_remove(bin_tree, 1);
    bin_tree_inorder(bin_tree);
    free_bin_tree(bin_tree);

    Avl_Tree *avl_tree = new_avl_tree();
    avl_tree_insert(avl_tree, 2);
    avl_tree_insert(avl_tree, 3);
    avl_tree_insert(avl_tree, 4);
    avl_tree_inorder(avl_tree);
    avl_tree_remove(avl_tree, 3);
    avl_tree_inorder(avl_tree);
    free_avl_tree(avl_tree);

    Skiplist *skiplist = new_skiplist();
    skiplist_insert(skiplist, 2);
    skiplist_insert(skiplist, 3);
    skiplist_insert(skiplist, 4);
    skiplist_print(skiplist);
    int found = skiplist_search(skiplist, 3);
    if (found) printf("found 3 in skiplist!\n");
    skiplist_remove(skiplist, 3);
    skiplist_print(skiplist);
    free_skiplist(skiplist);
}
