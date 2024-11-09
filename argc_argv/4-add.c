#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Adds positive numbers.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 if successful, 1 if an argument contains non-digit symbols.
 */
int main(int argc, char *argv[])
{
	int totalSum = 0;
	int argIndex, charIndex;


	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (argIndex = 1; argIndex < argc; argIndex++)
	{
		for (charIndex = 0; argv[argIndex][charIndex] != '\0'; charIndex++)
		{
			if (!isdigit(argv[argIndex][charIndex]))
			{
				printf("Error\n");
				return (1);
			}
		}
		totalSum += atoi(argv[argIndex]);
	}
	printf("%d\n", totalSum);
	return (0);
}
