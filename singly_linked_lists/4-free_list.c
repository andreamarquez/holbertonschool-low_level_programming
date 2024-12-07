#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * free_list - Frees a singly linked list.
 * @head: Pointer to the head of the list to be freed.
 *
 * Description: This function iterates through a singly linked list and frees
 * each node, including the strings stored in each node.
 */
void free_list(list_t *head)
{
	list_t *traverse_pointer;

	while (head != NULL)
	{
		traverse_pointer = head;
		head = head->next;
		free(traverse_pointer->str);
		free(traverse_pointer);
	}
}
