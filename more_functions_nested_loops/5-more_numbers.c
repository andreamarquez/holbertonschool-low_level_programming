#include "main.h"

/**
 * more_numbers - print numbers 0 to 14 10 times
 * requirement: followed by a new line
 * Return: 0.
 */
void more_numbers(void)
{
	int printer;
	int number;

	for (printer = 0; printer < 10; printer ++) /* loop for 10 lines */
	{
		for (number = 0; number <= 14; number++) /* loop for numbers 0 to 14 */
		{
			int units= number % 10;
			int tens= (number/10) % 10;
			if (tens > 0) 
			{	 
				_putchar('0' + tens);
			}
			_putchar('0' + units);
		}
		/** Prints new line after the inner loops finishes */
		_putchar('\n');
	}		

}	
