#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node.
 * @value: Value to insert.
 * Return: Pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;

	if (root == NULL)
		return (NULL);

	/* Case: Empty tree, create root */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the first available parent (BFS) */
	parent = find_insertion_parent(*root);
	if (parent == NULL)
		return (NULL); /* Should not happen in a complete heap */

	/* Insert new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL); /* Malloc failed */

	/* Attach to left if available, else right */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		int temp = new_node->n;

		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}

/**
 * find_insertion_parent - Finds the first available parent in level-order.
 * @root: Root of the heap.
 * Return: Pointer to the parent node,
 * or NULL if tree is full (should not happen in a heap).
 */
heap_t *find_insertion_parent(heap_t *root)
{
	heap_t **queue = NULL;
	size_t front = 0, rear = 0;
	heap_t *current = NULL;

	if (root == NULL)
		return (NULL);

	/* Initialize a queue for BFS */
	queue = malloc(sizeof(heap_t *) * 1024); /* Adjust size as needed */
	if (queue == NULL)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];

		/* If left is free, return this node */
		if (current->left == NULL)
		{
			free(queue);
			return (current);
		}
		else
			queue[rear++] = current->left;

		/* If right is free, return this node */
		if (current->right == NULL)
		{
			free(queue);
			return (current);
		}
		else
			queue[rear++] = current->right;
	}

	free(queue);
	return (NULL); /* Should not happen in a complete heap */
}
