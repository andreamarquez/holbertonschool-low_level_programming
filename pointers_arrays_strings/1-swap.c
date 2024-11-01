#include "main.h"

/**
 * swap_int - Swaps the values of two integers.
 * @pa: pointer that swaps with pointer b.
 * @pb: pointer that swaps with pointer a.
 *
 */
void swap_int(int *pa, int *pb)
{
	int temporal;

	temporal = *pa;
	*pa = *pb;
	*pb = temporal;
}
