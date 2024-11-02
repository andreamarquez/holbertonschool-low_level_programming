#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *dest_start = dest;

	/* Move to the end of dest string */
	while (*dest != '\0')
		dest++;

	/* Append src to dest */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Add the terminating null byte */
	*dest = '\0';

	return (dest_start);
}
