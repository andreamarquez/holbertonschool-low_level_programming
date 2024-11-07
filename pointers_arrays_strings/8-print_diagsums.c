#include <stdio.h>
#include "main.h"

/**
 *print_diagsums - prints the sum of the two diagonals of a square matrix of integers.
 * @matrix:
 * @size:
 */
void print_diagsums(int *a, int size)
{
    int index;
    int primary_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    for (index = 0; index < size; index++) {
		/* Sum for primary diagonal */
		primary_diagonal_sum = primary_diagonal_sum + a[index + (index * size)];
		/* Sum for secondary diagonal */
		secondary_diagonal_sum = secondary_diagonal_sum + a[(size - 1 - index) + (index * size)];
    }

    printf("%d, %d\n", primary_diagonal_sum, secondary_diagonal_sum);
}
