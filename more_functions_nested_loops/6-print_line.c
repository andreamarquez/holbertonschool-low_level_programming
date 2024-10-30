#include "main.h"

/**
 * print_line - draws a straight line in the terminal.
 * @n: the number of times the character _ should be printed.
 * The line should end with a \n.
 * If n is 0 or less, the function should only print \n.
 * Return: void.
 */
void print_line(int n)
{
	if (n <= 0)
	{
		_putchar ('\n'); 
	}
	else
	{
		int underscoreCounter;
		
		for(underscoreCounter = 0; underscoreCounter < n; underscoreCounter++)
		{
			_putchar('_');
		}
		_putchar('\n');		
	}

}
