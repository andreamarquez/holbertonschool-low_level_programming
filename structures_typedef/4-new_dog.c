#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

char *_strdup(char *str);

/**
 * new_dog - creates a new dog.
 * Store a copy of name and owner.
 * @name: Name of the dog.
 * @age: The age of the dog.
 * @owner: The owner of the dog.
 * Return: NULL if function fails, or a pointer
 * to the dog_t that was created.
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *p_doggy;

	if (name == NULL || owner == NULL)
		return (NULL);

	p_doggy = malloc(sizeof(dog_t));

	if (p_doggy == NULL)
	{
		return (NULL);
	}

	p_doggy->name = _strdup(name);
	if (p_doggy->name == NULL)
	{
		free(p_doggy);
		return (NULL);
	}

	p_doggy->owner = _strdup(owner);
	if (p_doggy->owner == NULL)
	{
		free(p_doggy->name);
		free(p_doggy);
		return (NULL);
	}

	p_doggy->age = age;

	return (p_doggy);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: string to copy
 *
 * Return: Pointer
 */
char *_strdup(char *str)
{
	int l, i;
	char *s;

	if (str == NULL)
		return (0);

	l = 0;
	while (*(str + l))
		l++;

	s = malloc(sizeof(char) * l + 1);

	if (s == 0)
		return (0);

	for (i = 0; i <= l; i++)
	{
		*(s + i) = *(str + i);
	}
	return (s);
}
