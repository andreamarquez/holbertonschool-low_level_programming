#include <stdio.h>
#include "main.h"

/**
 * print_array - prints "n" elements (numberOfElementsToPrint)
 * of an array of integers (arr), followed by a new line.
 *
 *
 * @arr: array to print
 * @numberOfElementsToPrint: `pointer` to the string that will be used
 *
 */
void print_array(int *arr, int numberOfElementsToPrint)
{
	int currentIndex;

	/*
	* just until we print the numberOfElementsToPrint or until
	* the size of array is found (shouldn't try to print more
	* elements id the array already ended).
	*
	*/
	for (
		currentIndex = 0;
		(currentIndex < numberOfElementsToPrint);
		currentIndex++
		)
	{
		printf("%d ,", arr[currentIndex]);
	}

	printf("\n");
}
