#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node;

	if (!list)
		return (NULL);
	node = list;
	while (node)
	{
		if (node->n < value && !node->index == 0)
		{
			printf("Value checked at index [%lu] = [%d]\n",
					node->index, node->n);
		}
		if (node->express == NULL)
		{
			return (found_at_end(node, value));
		}
		if (node->express->n >= value)
		{
			return (found_between(node, value));
		}
		if (node->express)
		{
			node = node->express;
		}
	}
	return (NULL);
}

/**
 * found_between - Searches for a value between two nodes in a skip list
 * @list: Pointer to the starting node of the range
 * @value: Value to search for
 * Return: Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *found_between(skiplist_t *list, int value)
{
	skiplist_t *node;

	node = list;
	printf("Value checked at index [%lu] = [%d]\n",
					node->express->index, node->express->n);
	printf("Value found between indexes [%lu] and [%lu]\n",
			node->index, node->express->index);
	while (node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		node = node->next;
	}
	if (node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		return (node);
	}
	return (NULL);
}

/**
 * found_at_end - Searches for a value starting
 * from the end of a skip list
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to the node containing the value, or NULL if not found
 */
skiplist_t *found_at_end(skiplist_t *list, int value)
{
	skiplist_t *last_node = list;
	skiplist_t *node = list;

	while (last_node->next)
	{
		last_node = last_node->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			node->index, last_node->index);
	while (node->n < value && node->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		node = node->next;
	}
	if (node->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		return (node);
	}
	printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	return (NULL);
}
