#include "binary_trees.h"
#include <stdbool.h>
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}


/**
 * binary_tree_is_avl_helper - Helper function to check AVL property
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for BST property
 * @max: Maximum value for BST property
 *
 * Return: 1 if tree is AVL, 0 otherwise
 */
int binary_tree_is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	int left_depth, right_depth, balance_factor;

	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_depth = depth(tree->left);
	right_depth = depth(tree->right);
	balance_factor = left_depth - right_depth;

	if (balance_factor < -1 || balance_factor > 1)
		return (0);

	return (binary_tree_is_avl_helper(tree->left, min, tree->n - 1) &&
		binary_tree_is_avl_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_helper(tree, -2147483648, 2147483647));
}

/**
 * depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Depth of the tree, 0 if tree is NULL
 */
int depth(const binary_tree_t *tree)
{
	int left_depth, right_depth;

	if (tree == NULL)
		return (0);

	left_depth = depth(tree->left);
	right_depth = depth(tree->right);

	return ((left_depth > right_depth ? left_depth : right_depth) + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value allowed
 * @max: Maximum value allowed
 *
 * Return: true if tree is a valid BST, false otherwise
 */
bool is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (true);

	if (tree->n < min || tree->n > max)
		return (false);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}
