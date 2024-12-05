#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_nodes - Adds multiple nodes to the end of the list.
 * @head: Double pointer to the head of the doubly linked list.
 * @values: Array of integer values to be added.
 * @count: Number of values in the array.
 */
void add_nodes(dlistint_t **head, int *values, size_t count)
{
    size_t i;
    for (i = 0; i < count; i++)
    {
        add_dnodeint_end(head, values[i]);
    }
}

/**
 * delete_nodes_at_index - Deletes nodes at the beginning of the
 * list multiple times.
 * @head: Double pointer to the head of the doubly linked list.
 * @times: Number of times to delete the node at the beginning.
 */
void delete_nodes_at_index(dlistint_t **head, unsigned int times)
{
    unsigned int i;
    for (i = 0; i < times; i++)
    {
        delete_dnodeint_at_index(head, 0);
        print_dlistint(*head);
        printf("-----------------\n");
    }
}

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    dlistint_t *head;
    int values[] = {0, 1, 2, 3, 4, 98, 402, 1024};

    head = NULL;
    add_nodes(&head, values, sizeof(values) / sizeof(values[0]));
    print_dlistint(head);
    printf("-----------------\n");

    delete_dnodeint_at_index(&head, 5);
    print_dlistint(head);
    printf("-----------------\n");

    delete_nodes_at_index(&head, 9);

    return (EXIT_SUCCESS);
}
