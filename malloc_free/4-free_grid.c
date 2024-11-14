#include <stdlib.h>

/**
 * free_grid -  returns a pointer to a 2 dimensional
 * array of integers.
 * Each element of the 2D array, should be initialized to 0.
 * @width: wide of the array.
 * @height: height of the array.
 * Return: NULL if it fails to allocate memory, otherwise
 * return the 2 dimensional array.
 * If either width or height is 0 or negative, the function should
 * return NULL.
 */
void free_grid(int **grid, int height);