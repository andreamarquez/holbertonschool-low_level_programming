#include "main.h"

int _isdigit(int charToCheck);

/**
 * _atoi - convert a string to an integer
 * The number in the string can be preceded
 * by an infinite number of characters, so we need to ignore
 * any non int, ex:
 * "+bla?la+ded98" -> 98
 * "-bla?la+ded98" -> -98
 * we need to take into account all the
 * - and + signs before the number, for example
 * "-++--98" -> we can ignore the "+", but we have to count the
 * minus, there are 3, we can apply the sign rule (- * -) = + ,
 * we used 2 minus, a 3th is still there, so - * + = -
 * "-++--98" -> should be -98
 *
 * The idea:
 * as we are iterating the string, we need to stop at
 * the null terminator character '\0' (we know this
 * because this is a char pointer, char pointers end on null
 * terminator)
 *
 * We need to filter the non numerics,
 * also, we need to store the (minus -)
 * lastly each time we find a numeric character
 * (so any ASCII between 48 and 57), we need to store it
 * if we find another one, first we multiply by 10
 * what we already had and then we add the new found digit
 *
 * @s: the string to convert as in "198" in chars
 *
 * Return: the string converted to int, ex: "198" converted to 198
 *
 */
int _atoi(char *s)
{
	int charCounter = 0;
	char currentChar = *s;
	char *nextPointer;
	/*
	* signResult will, be either 1 for positive, 0 for negative
	* depending on the number of minuses we find
	*/
	int signResult = 1;
	int result = 0;
	int currentCharToInt;

	while (currentChar != '\0')
	{
		charCounter++;
		nextPointer = (s + charCounter);

		currentChar = *nextPointer;
		if (currentChar == '-')
			signResult = signResult * -1;
		else if (_isdigit(currentChar))
		{
			/*
			* as here we know it is a numeric ASCII (a digit)
			* we take the ASCII code and remove 48 from it (the ASCII for 0)
			* '0' which in ASCII is 48, if subtracted 48, will give us the int 0
			* '1' which in ASCII is 49, if subtracted 48, will give us the int 1
			* ...
			* '9' which in ASCII is 57, if subtracted 48, will give us the int 9
			*/
			currentCharToInt = currentChar - 48;

			result = result * 10;

			result = result + currentCharToInt;
		}
	}
	/* give the result a sign */
	result = result * signResult;

	return (result);
}

/**
 * _isdigit - checks for a digit (0 through 9).
 * @charToCheck: ASCII code or char, the Digit to check.
 *
 * Return: 1 if is a digit, 0 otherwise.
 */
int _isdigit(int charToCheck)
{
	/*
	* 48 is the ASCII of 0,
	* 57 is the ASCII of 9
	*/
	if (charToCheck >= 48 && charToCheck <= 57)
		return (1);
	else
		return (0);
}

