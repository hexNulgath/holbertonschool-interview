
#include "binary_trees.h"
#include <stdlib.h>

/**
 * swap_values - Swap the values of two nodes
 */
void swap_values(heap_t *a, heap_t *b)
{
    int tmp = a->n;
    a->n = b->n;
    b->n = tmp;
}

/**
 * tree_height - Measures the height of a binary tree
 */
size_t tree_height(const heap_t *tree)
{
    size_t l, r;
    if (!tree)
        return 0;
    l = tree_height(tree->left);
    r = tree_height(tree->right);
    return 1 + (l > r ? l : r);
}

/**
 * get_last_node - Finds the last node in level order
 */
heap_t *get_last_node(heap_t *root)
{
    size_t h = tree_height(root), mask = 1UL << (h - 2);
    heap_t *node = root;
    if (!root || h == 1)
        return root;
    while (mask)
    {
        if ((mask & (1UL << (h - 2))) && node->right)
            node = node->right;
        else if (node->left)
            node = node->left;
        mask >>= 1;
    }
    return node;
}

/**
 * sift_down - Heapify down from the root
 */
void sift_down(heap_t *node)
{
    heap_t *largest;
    while (node)
    {
        largest = node;
        if (node->left && node->left->n > largest->n)
            largest = node->left;
        if (node->right && node->right->n > largest->n)
            largest = node->right;
        if (largest == node)
            break;
        swap_values(node, largest);
        node = largest;
    }
}

/**
 * heap_extract - Extracts the root value of a max heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    heap_t *last, *parent;
    size_t h;
    int value;
    unsigned long mask;
    if (!root || !*root)
        return 0;
    value = (*root)->n;
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return value;
    }
    last = *root;
    h = tree_height(*root), mask = 1UL << (h - 2);
    parent = NULL;
    while (mask)
    {
        parent = last;
        if ((mask & (1UL << (h - 2))) && last->right)
            last = last->right;
        else if (last->left)
            last = last->left;
        mask >>= 1;
    }
    (*root)->n = last->n;
    if (parent)
    {
        if (parent->left == last)
            parent->left = NULL;
        else if (parent->right == last)
            parent->right = NULL;
    }
    free(last);
    sift_down(*root);
    return value;
}