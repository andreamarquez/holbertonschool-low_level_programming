#include <stdlib.h>
#include <string.h>
/**
 * string_nconcat - concatenate two strings.
 * The returned pointer points to a newly allocated space in memory that
 * contains string_1 followed by the "x" first number of characters of the
 * string_2 and then, the null terminator.
 * If string_1 or string_2 are NULL, we treat it as empty strings.
 * If the "x" number_of_char is > or = to the length of the string_2, we use
 * the entire string.
 * @string_1: first string.
 * @string_2: second string.
 * @number_of_char: the first 'x' number of characters to be added after
 * the string_1.
 * Return: If the allocation of the memory fails it returns NULL and
 * if it works, returns a pointer who points to the new chain made with
 * string_1 and the first "x" number_of_char of string_2 and the null
 * terminator.
 */
char *string_nconcat(char *string_1,
					char *string_2,
					unsigned int number_of_char)
{
	unsigned int length_s1;
    unsigned int length_s2;
	unsigned int counter;
	unsigned int counter2;
	char *new_string;
	/*
	* Checks if string_1 or string_2 are NULL, if NULL, they will be
	* empty strings
	*/
	if (string_1 == NULL)
		string_1 = "";

	if (string_2 == NULL)
		string_2 = "";

	/* Checks the length of the string*/
	length_s1 = strlen(string_1);
	length_s2 = strlen(string_2);

	if (number_of_char >= length_s2)
		number_of_char = length_s2;

	/*Allocates memory for the new string*/
	new_string = malloc(length_s1 + number_of_char + 1);
		if (new_string == NULL)
		return (NULL);

	/*Copy string_1 to new_string*/
	for (counter = 0; counter < length_s1; counter++)
	new_string[counter] = string_1[counter];

	/* Copy the first number_of_char characters of string_2 to new_string */
	for (counter2 = 0; counter2 < number_of_char; counter2++)
		new_string[length_s1 + counter2] = string_2[counter2];

	/* Adding the null terminator at the end*/
	new_string[length_s1 + number_of_char] = '\0';

	return (new_string);
}
