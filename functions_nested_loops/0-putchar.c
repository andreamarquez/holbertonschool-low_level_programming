#include "main.h"
/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	char phrase[8] = "_putchar";

	int index;

	for (index = 0; index <= 7; index++)
	{
		_putchar(phrase[index]);
	}

	_putchar('\n');
	return (0);
}

