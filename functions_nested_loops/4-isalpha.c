#include "main.h"

/**
 * _isalpha - checks for alphabetic character, given an ASCII code.
 * @c: The ASCII character code to check.
 *
 * Return: an int 1 if c (in ASCII code) is an alphabetic character ASCII,
 * otherwise returns 0.
 */
int _isalpha(int c)
{
	int lowercasea = 97;
	int lowercasez = 122;
	int uppercaseA = 65;
	int uppercaseZ = 90;

	if (
		((c >= uppercaseA) && (c <= uppercaseZ))
		||
		((c >= lowercasea) && (c <= lowercasez))
		)
		return (1);
	else
		return (0);
}

