#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to be used from src
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *dest_start = dest;
	int i;

	/* Move to the end of dest string */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Append src to dest, using at most n bytes */
	for (i = 0; i < n && *src != '\0'; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Add the terminating null byte */
	*dest = '\0';

return (dest_start);
}
