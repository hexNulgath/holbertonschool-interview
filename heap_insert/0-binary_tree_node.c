#include "binary_trees.h"
#include <stdlib.h>

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    if (node == NULL)
        return (NULL);

    node->n = value;
    node->parent = parent;
    if (parent != NULL)
    {
        if (value < parent->n)
            parent->left = node;
        else
            parent->right = node;
    }
    else
    {
        node->left = NULL;
        node->right = NULL;
    }

    return (node);
}
