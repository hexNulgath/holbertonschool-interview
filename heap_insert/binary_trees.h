#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef binary_tree_t heap_t; // heap_t is now an alias for binary_tree_t

/* Binary Tree Utility Functions */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value); // Function for creating a new binary tree node

/* Heap-specific Functions */
heap_t *heap_insert(heap_t **root, int value); // Inserts a node into a heap
heap_t *find_insertion_parent(heap_t *root);   // Finds the first available parent for insertion in a heap

/* Printing Functions */
void binary_tree_print(const binary_tree_t *); // Function to print the binary tree

#endif /* _BINARY_TREES_H_ */
