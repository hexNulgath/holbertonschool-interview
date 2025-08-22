#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree
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
 * @root: Pointer to the root node
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
    size_t height;
    heap_t **queue, *last = NULL;
    int front = 0, rear = 0;
    
    if (!root)
        return NULL;
    
    height = tree_height(root);
    queue = malloc(sizeof(heap_t *) * (1 << height));
    if (!queue)
        return NULL;
    
    queue[rear++] = root;
    
    while (front < rear)
    {
        heap_t *current = queue[front++];
        last = current;
        
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    
    free(queue);
    return last;
}

/**
 * heapify_down - Restores max heap property from root downward
 * @root: Pointer to the root node
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    int temp;
    
    if (root->left && root->left->n > largest->n)
        largest = root->left;
    
    if (root->right && root->right->n > largest->n)
        largest = root->right;
    
    if (largest != root)
    {
        temp = root->n;
        root->n = largest->n;
        largest->n = temp;
        heapify_down(largest);
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
    int value;
    
    if (!root || !*root)
        return 0;
    
    value = (*root)->n;
    
    if (!(*root)->left && !(*root)->right)
    {
        free(*root);
        *root = NULL;
        return value;
    }
    
    last = get_last_node(*root);
    if (!last)
        return 0;
    
    (*root)->n = last->n;
    
    parent = last->parent;
    if (parent)
    {
        if (parent->left == last)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    
    free(last);
    heapify_down(*root);
    
    return value;
}