#include <string.h>
#include <stdlib.h>

int _strlen(char *ps);

/**
 * str_concat - concatenates two strings.
 * Returned pointer points to newly allocated
 * space in memory which contains s1 followed by S2 and
 * ends with a null terminator (\0).
 * If NULL is passed, we treat it as -> empty string.
 *
 * @s1: first string.
 * @s2: second string.
 * Return: NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	int s1index = 0;
	int s2index = 0;
	int length1;
	int length2;

	if (s1 == NULL && s2 == NULL)
	{
		s3 = "";
		return (s3);
	}

	length1 = _strlen(s1);
	length2 = _strlen(s2);

	s3 = malloc(((length1 + length2) + 1) * sizeof(char));

	if (s3 == NULL)
	{
		return (NULL);
	}

	if (s1 != NULL)
	{
		for (s1index = 0; s1index < length1; s1index++)
		{
			s3[s1index] = s1[s1index];
		}
	}

	if (s2 != NULL)
	{
		for (s2index = 0; s2index < length2; s2index++)
		{
			s3[s1index + s2index] = s2[s2index];
		}
	}

	s3[s1index + s2index] = '\0';
	return (s3);
}

/**
 *  _strlen - Returns the length of a string.
 * @ps: pointer that points to the string ("chain of characters").
 * Return: string length (int)
 *
 */
int _strlen(char *ps)
{
	int charCounter = 0;

	char currentChar = *ps;
	char *nextPointer;

	if (ps == NULL)
	{
		return (charCounter);
	}

	while (currentChar != '\0')
	{
		charCounter++;
		nextPointer = (ps + charCounter);

		currentChar = *nextPointer;
	}
	return (charCounter);
}