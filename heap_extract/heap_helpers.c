#include "binary_trees.h"
#include <stdlib.h>

/* Helper to insert a value in a max heap (simple, not optimal) */
static heap_t *insert(heap_t *root, int value)
{
    if (!root)
    {
        heap_t *node = malloc(sizeof(heap_t));
        if (!node) return NULL;
        node->n = value;
        node->left = node->right = node->parent = NULL;
        return node;
    }
    if (!root->left)
    {
        root->left = insert(NULL, value);
        if (root->left) root->left->parent = root;
        return root;
    }
    if (!root->right)
    {
        root->right = insert(NULL, value);
        if (root->right) root->right->parent = root;
        return root;
    }
    if (rand() % 2)
        insert(root->left, value);
    else
        insert(root->right, value);
    return root;
}

heap_t *_array_to_heap(int *array, size_t size)
{
    heap_t *root = NULL;
    size_t i;
    for (i = 0; i < size; i++)
        root = insert(root, array[i]);
    return root;
}

void _binary_tree_delete(binary_tree_t *tree)
{
    if (!tree) return;
    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}
