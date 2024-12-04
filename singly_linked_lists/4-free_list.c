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
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
