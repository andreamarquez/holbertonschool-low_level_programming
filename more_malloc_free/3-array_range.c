#include <stdlib.h>

/**
 * array_range - creates an array of integers,
 * from range_start (included) to range_end(included),
 * Example:
 * if range_start is 3 and range_end is 7,
 * then array_range should return an array like
 * [3, 4, 5, 6, 7]
 *
 * @range_start: the number to start from
 * @range_end: the the final value for the array range
 *
 * Return: an ordered array of ints.
 */
int *array_range(int range_start, int range_end)
{
	int *array_from_range;
	int num_of_elements_in_range;
	int element_index;

	if (range_start > range_end)
		return (NULL);

	/* Ex: from 1 to 4 -> gives 1, 2, 3, 4 */
	/* so there are 4 elements, 4 - 1 gives 3 in length */
	/* to compensate the missing one, the +1 is added */
	num_of_elements_in_range = (range_end - range_start) + 1;
	array_from_range = malloc(num_of_elements_in_range * sizeof(int));

	if (array_from_range == NULL)
		return (NULL);

	/* Fill the array with values from range_start to range_end */
	for (
		element_index = 0;
		element_index < num_of_elements_in_range;
		element_index++
		)
	{
		/* From range_start we keep adding an index */
		array_from_range[element_index] = range_start + element_index;
	}
	return (array_from_range);
}
