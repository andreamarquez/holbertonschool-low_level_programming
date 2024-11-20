#include <stdlib.h>
#include "3-calc.h"

/**
 * get_op_func - Selects the correct function to perform the operation
 *               requested by the user.
 * @s: The operator passed as argument to the program.
 *
 * Return: A pointer to the function that corresponds to the operator
 *         given as a parameter. If the operator does not match any of
 *         the expected operators, return NULL.
 *         int (*function)(int a, int b)
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

	/* we only try the check if the string param has only one */
	/* character, ex: "*+" has two chars so it */
	/* means s[1] is "+" and not a null terminator */
	while ((ops[i].operator != NULL) && s[1] == '\0')
	{
		if (s[0] == ops[i].operator[0])
			return (ops[i].f);
		i++;
	}

	/* no match found after running the while */
	return (NULL);
}
