#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node at the end of a double circular linked list
 * @list: Double pointer to the head of the list
 * @str: String to be stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *last;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!*list)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}
	new_node->next = *list;

	last = (*list)->prev;
	(*list)->prev = new_node;
	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of a double circular list
 * @list: Double pointer to the head of the list
 * @str: String to be stored in the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *last;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	if (!*list)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
		return (new_node);
	}
	last = (*list)->prev;
	new_node->next = *list;
	new_node->prev = last;
	(*list)->prev = new_node;
	last->next = new_node;
	*list = new_node;
	return (new_node);
}
