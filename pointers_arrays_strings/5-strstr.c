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
 * If the substring is empty, the function should return
 * the main_string itself. This is because an empty substring
 * is considered to be found at the beginning of any string,
 * including an empty main_string.
 */
char *_strstr(char *main_string, char *substring)
{
	int substring_counter = 0;
	int main_string_counter;
	int characterFound = 0;

	if (*substring == '\0')
		return (main_string);

	for (
		main_string_counter = 0;
		(*(main_string + main_string_counter)) != '\0';
		main_string_counter++
		)
	{
		if (*(main_string + main_string_counter) == *(substring))
		{
			characterFound = 1;
			for (
				substring_counter = 0;
				*(substring + substring_counter) != '\0';
				substring_counter++
				)
			{
				if (
					*(main_string + main_string_counter + substring_counter)
					!= *(substring + substring_counter)
					)
				{
					characterFound = 0;
					break;
				}
			}
			if (characterFound == 1)
				return (main_string + main_string_counter);
		}
	}
	return (NULL);
}
