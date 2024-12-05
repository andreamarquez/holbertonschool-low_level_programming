#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 *
 * Description: This function traverses a doubly linked list and frees
 * each node, releasing the memory allocated for the list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
