#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * main - calculator.
 * @argc: The number of command-line arguments (the count
 * includes the file_name), so it is minimum one.
 *
 * @argv: An array of pointers to the arguments.
 * [file_name, first_arg, etc]
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{
	int expected_args_count = 4;
	int incorrect_args_length_error = 98;
	int no_valid_operator_found_error = 99;
	int first_number;
	int second_number;
	char *operator_symbol;
	int (*op_func)(int a, int b);
	int result;

	if (argc != expected_args_count)
	{
		printf("Error\n");
		exit(incorrect_args_length_error);
	}

	operator_symbol = argv[2];

	op_func = get_op_func(operator_symbol);

	if (op_func == NULL)
	{
		printf("Error\n");
		exit(no_valid_operator_found_error);
	}

	first_number = atoi(argv[1]);
	second_number = atoi(argv[3]);

	result = op_func(first_number, second_number);
	printf("%d\n", result);

	return (0);
}
