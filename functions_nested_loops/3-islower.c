#include "main.h"

/**
 * _islower - checks for lowercase letter
 * @c: The character code to check
 *
 * Return: On lowercase, returns 1, else 0.
 */
int _islower(int c)
{
	if ((c >= 97) && (c <= 97))
		return (1);
	else
		return (0);
}
