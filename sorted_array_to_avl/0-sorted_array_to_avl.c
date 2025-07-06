#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * sorted array to avl
 *
 * sorted_array_to_avl - Converts a sorted array to an AVL tree.
 *
 * Parameters:
 *   Where array is a pointer to the first element of the array to be converted
 *	 And size is the number of element in the array
 *   
 *
 * Returns:
 *   a pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
		if (size == 0 || array == NULL)
				return (NULL);
		size_t mid;
		if (size % 2 == 0)
				// If size is even, choose the left middle element
				// to maintain balance in the AVL tree.
				mid = size / 2 - 1;
		else
				// If size is odd, choose the exact middle element.
				mid = size / 2;

		avl_t *root = malloc(sizeof(avl_t));
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
