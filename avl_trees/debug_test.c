#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

binary_tree_t *basic_tree(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left = binary_tree_node(root->left, 10);
    return (root);
}

int main(void)
{
    binary_tree_t *root;
    
    root = basic_tree();
    root->right->right->right = binary_tree_node(root->right->right, 430);
    
    printf("Root left depth: %d\n", depth(root->left));
    printf("Root right depth: %d\n", depth(root->right));
    printf("Balance factor: %d\n", depth(root->left) - depth(root->right));
    printf("Is BST: %d\n", is_bst(root, -2147483648, 2147483647));
    printf("Is AVL: %d\n", binary_tree_is_avl(root));
    
    binary_tree_print(root);
    
    return (0);
}
