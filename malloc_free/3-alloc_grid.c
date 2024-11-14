#include <stdlib.h>

/**
 * alloc_grid -  returns a pointer to a 2 dimensional
 * array of integers.
 * Each element of the 2D array, should be initialized to 0.
 * @width: wide of the array.
 * @height: height of the array.
 * Return: NULL if it fails to allocate memory, otherwise
 * return the 2 dimensional array.
 * If either width or height is 0 or negative, the function should
 * return NULL.
 */
int **alloc_grid(int width, int height)
{
	int **array2D;

	int counter;
	int vertical_index;
	int horizontal_index;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}
	array2D = malloc(height * sizeof(int *));

	if (array2D == NULL)
	{
		return (NULL);
	}

	for (counter = 0; counter < height; counter++)
	{
		array2D[counter] = malloc(width * sizeof(int));
	}

	for (vertical_index = 0; vertical_index < height; vertical_index++)
	{
		for (horizontal_index = 0; horizontal_index < width; horizontal_index++)
		{
			array2D[vertical_index][horizontal_index] = 0;
		}
	}
	return (array2D);
}

