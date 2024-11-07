#include <stdio.h>
#include "main.h"

/**
 *_strstr - Locates the first character on the substring, that
 * matches with any character of the main string.
 * @substring: Where we take character by character
 * to see if the character exists on the main_string.
 * @main_string: The string containing the characters that
 * may match with some character of the substring.
 * Return: NULL if any character of the main_string matches
 * with the substring OR returns a pointer of the character
 * in the substring that matches with the main_string.
 */
char *_strstr(char *main_string, char *substring)
{
	int counter;
	int second_counter;

	for (counter = 0; (*(substring + counter) != '\0'); counter++)
	{
		for (second_counter = 0; (*(main_string + second_counter) != '\0');
		second_counter++)
		{
			if ((*(substring + counter)) == (*(main_string + second_counter)))
			{
				return ((substring + counter));
			}
		}
	}
	return (NULL);
}
