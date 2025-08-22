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
typedef struct binary_tree_s heap_t;

void swap_values(heap_t *a, heap_t *b);
size_t tree_height(const heap_t *tree);
heap_t *get_last_node(heap_t *root);
void sift_down(heap_t *node);
void binary_tree_print(const binary_tree_t *);
int heap_extract(heap_t **root);
heap_t *_array_to_heap(int *array, size_t size);
void binary_tree_print(const binary_tree_t *tree);
void _binary_tree_delete(binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */