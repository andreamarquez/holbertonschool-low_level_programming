#include <stdlib.h>

/**
 * free_grid - frees the 2 dimensional array previously created by
 * the alloc_grid function (deallocate the memory that was
 * previously allocated).
 * @array2D: the 2D array of integers.
 * @height: height of the array.
 * Return: void.
 */
void free_grid(int **array2D, int height)
{
	int array_to_free_counter;

	if (array2D == NULL)
		return;

	for (
		array_to_free_counter = 0;
		array_to_free_counter < height;
		array_to_free_counter++
		)
	{
		if (array2D[array_to_free_counter] != NULL)
			free(array2D[array_to_free_counter]);
	}
	free(array2D);
}
