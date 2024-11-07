#include <stdio.h>
#include "main.h"

/**
 * print_chessboard - Prints the chessboard.
 * @a: the 2 dimension array pointer
 */
void print_chessboard(char (*a)[8])
{
	int main_counter;
	int sub_counter;

	for (main_counter = 0; main_counter < 8; main_counter++)
	{
		for (sub_counter = 0; sub_counter < 8; sub_counter++)
		{
			putchar(a[main_counter][sub_counter]);
		}
		putchar('\n');
	}
}
