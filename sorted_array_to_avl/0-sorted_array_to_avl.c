#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree.
 * @array: Pointer to the first element of the sorted array to be converted.
 * @size: Number of elements in the array.
 *
 * Description: Recursively builds a height-balanced AVL tree
 * from a sorted array.
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t mid;
	avl_t *root;

	if (size == 0 || array == NULL)
		return (NULL);
	if (size % 2 == 0)
		mid = size / 2 - 1;
	else
		mid = size / 2;
	root = malloc(sizeof(avl_t));

	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = NULL;
	root->left = sorted_array_to_avl(array, mid);
	root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;

	return (root);
}
