int find_prime(int number_to_check, int current_number);

/**
 * is_prime_number - tests if the number is prime.
 * @n: the number to be tested if it is prime or not.
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 * negative numbers can't be prime.
 *
 */
int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	return (find_prime(n, 2));
}

/**
 * find_prime - tests if the number is prime.
 * @number_to_check: the number to be tested if it is prime or not.
 * @current_number: the number on the current iteration to test (ex,
 * if number_to_check is 17, we start on 3 and keep incrementing)
 *
 * Return: 1 if the input integer is a prime number, otherwise return 0.
 *
 */
int find_prime(int number_to_check, int current_number)
{
	if (number_to_check <= current_number)
		return (1);
	else if (number_to_check % current_number == 0)
	{
		return (0);
	}
	else
	{
		return (find_prime(number_to_check, current_number + 1));
	}
}
