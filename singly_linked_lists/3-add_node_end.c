#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

int string_length(const char *string);

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @pointer_to_head: Double pointer to the head of the list.
 * @str: String to be duplicated and added to the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **pointer_to_head, const char *str)
{
	list_t *pointer_to_new_node;
	list_t *pointer_to_next_node;

	pointer_to_new_node = malloc(sizeof(list_t));
	if (pointer_to_new_node == NULL)
	{
		return (NULL);
	}

	pointer_to_new_node->str = strdup(str);
	pointer_to_new_node->len = string_length(str);
	pointer_to_new_node->next = NULL;

	if (*pointer_to_head == NULL)
	{
		*pointer_to_head = pointer_to_new_node;
		return (pointer_to_new_node);
	}

	pointer_to_next_node = *pointer_to_head;

	while (pointer_to_next_node != NULL)
	{
		if (pointer_to_next_node->next != NULL)
		{
			pointer_to_next_node = pointer_to_next_node->next;
		}
		else
		{
			pointer_to_next_node->next = pointer_to_new_node;
			pointer_to_next_node = NULL;
		}
	}

	return (pointer_to_new_node);

}

/**
 * string_length - Calculates the length of a string.
 * @string: The string whose length is to be calculated.
 *
 * Return: The length of the string.
 */
int string_length(const char *string)
{
	int length = 0;
	int counter;

	for (counter = 0; string && string[counter]; counter++)
	{
		length++;
	}

	return (length);
}
