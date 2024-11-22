#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 *               requested by the user.
 * @s: The operator passed as argument to the program from the terminal.
 *
 * Return: A pointer to the function that corresponds to the operator
 *         given as a parameter. If the operator does not match any of
 *         the expected operators, return NULL.
 *         type of the returned func pointer: int (*function)(int a, int b)
 */
int (*get_op_func(char *s))(int a, int b)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;

	/**
	 * s comes from terminal argv arguments, so it is a string.
	 * s tells us which operation we need to get, but it has to have
	 * only one char, therefore the second char has to be a null terminator
	 * if s[1] is '\0', it means our string has only one char
	 * which is OK as we ONLY expect one operator in the string, not
	 * many: "+" is OK, "+*" is NOT ok as it has two operators
	 * then s[1] won't be '\0' for the 2th example but will be "*"
	*/
	while ((ops[i].operator != NULL) && s[1] == '\0')
	{
		if (s[0] == ops[i].operator[0])
			return (ops[i].corresponding_function);
		i++;
	}

	/* no match found after running the while */
	return (NULL);
}
