#include <stdio.h>
#include "main.h"

/**
 * print_chessboard - Prints the chessboard.
 * @main_array: the 2 dimension array pointer
 */
void print_chessboard(char (*main_array)[8])
{
	int array_counter;
	int sub_counter;

	for (array_counter = 0; array_counter < 8; array_counter++)
	{
		for (sub_counter = 0; sub_counter < 8; sub_counter++)
		{
			putchar(main_array[array_counter][sub_counter]);
		}
		putchar('\n');
	}
}
