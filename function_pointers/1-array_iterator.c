#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - execute a function given as a parameter
 * on each element of the array.
 * @array: The array to iterate over.
 * @size: Size of the array.
 * @action: Pointer to the function to use.
 *
 * Return: Void.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t counter;

	/* Check if array or action is NULL */
	if (array == NULL || action == NULL)
		return;

	/*Iterate through each element of the array*/
	for (counter = 0; counter < size; counter++)
	{
		action(array[counter]);
	}
}
