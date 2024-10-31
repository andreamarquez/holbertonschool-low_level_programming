#include "stdio.h"

/**
 * main - Print numbers from 1 to 100
 * multiples of three -> print "Fizz"
 * multiples of five -> print "Buzz"
 * multiples of both -> print "FizzBuzz"
 * Return: 0.
 */

int main(void)
{
	int firstNumber = 1;
	int lastNumber = 100;
	int numberToPrint = 1;

	while ((firstNumber <= numberToPrint) && (numberToPrint <= lastNumber))
	{
		if (numberToPrint % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (numberToPrint % 5 == 0)
		{
			printf("Buzz ");
		}
		else if ((numberToPrint % 3 == 0) && (numberToPrint % 5 == 0))
		{
			printf("FizzBuzz ");
		}
		else
		{
		printf("%d ", numberToPrint);
		}
		numberToPrint++;

	}
}
