#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet in lower case 10 times
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int printCounter;

	for (printCounter = 1; printCounter <= 10; printCounter++)
	{
		int alphabetIndex;

		for (alphabetIndex = 97; alphabetIndex <= 122; alphabetIndex++)
		{
			_putchar(alphabetIndex);
		}
		_putchar('\n');
	}
}

