#include <stdio.h>
#include "main.h"

/**
 *_strpbrk - Locates a character in main_string,
 * that matches with any character of the secondary_string.
 * @main_string: Where we take character by character
 * to see if the character exists on the secondary_string.
 * @secondary_string: The string containing the characters that
 * may match with some character of the secondary_string.
 * Return: NULL if the character is not found, and if it is found,
 * the return is a pointer that points to the value of the character(s)
 * that matches.
 *
 */
char *_strpbrk(char *main_string, char *secondary_string)
{
	int counter;
	int second_counter;

	for (counter = 0; (*(main_string + counter) != '\0'); counter++)
	{
		for (second_counter = 0; (*(secondary_string + second_counter) != '\0');
			 second_counter++)
		{
			if ((*(main_string + counter)) == (*(secondary_string + second_counter)))
			{
				return (main_string + counter);
			}
		}

	}
	return (NULL);
}
