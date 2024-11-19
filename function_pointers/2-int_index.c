#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - Searches for an integer in the array that
 * matches a condition defined by the compare_function.
 * @array: The array where we search the integer.
 * @size: The number of elements in the array.
 * @compare_function: Returns 0 if their condition is not accomplished.
 * Return: Returns the index of the first element for which
 * the compare_function does not return 0.
 * If no element matches, return -1.
 * If size <= 0, return -1.
 */
int int_index(int *array, int size, int (*compare_function)(int))
{
	int position_counter;
	int matches_condition;

	/* Check if array or compare_function is NULL */
	if (array == NULL || compare_function == NULL)
		return (-1);

	/* Size check*/
	if (size <= 0)
		return (-1);

	/* Loop trough the array to see if the condition matches */
	for (position_counter = 0; position_counter < size; position_counter++)
	{
		matches_condition = compare_function(array[position_counter]);
		if (matches_condition != 0)
		{
			return (position_counter);
		}
	}
	return (-1);
}
