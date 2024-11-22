#ifndef CALC_STRUCTURES
#define CALC_STRUCTURES

/**
 * struct operation - Contains the operator and the function
 *
 * @operator: The operator
 * @f: The function associated
 */
typedef struct operation
{
	char *operator;
	int (*corresponding_function)(int a, int b);
} op_t;


#endif /* CALC_STRUCTURES */

#ifndef CALC_FUNCTIONS
#define CALC_FUNCTIONS

int (*get_op_func(char *s))(int, int);

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

#endif /* CALC_FUNCTIONS */
