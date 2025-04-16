#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *parent = NULL;
    parent = min_depth(*root);
    if (parent == NULL)
    {
        return (NULL);
    }

    binary_tree_node(*parent, int value);
}

heap_t *min_depth(heap_t *node)
{
    if (node == NULL)
    {
        return (NULL);
    }
    if (node->left == NULL && node->right == NULL)
    {
        return (node);
    }
    heap_t *left = min_depth(node->left);
    heap_t *right = min_depth(node->right);
    if (left == NULL)
    {
        return (right);
    }
    if (right == NULL)
    {
        return (left);
    }
    return (left->height < right->height ? left : right);
}