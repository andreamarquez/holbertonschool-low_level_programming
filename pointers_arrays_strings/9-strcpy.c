/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0), to the
 * buffer pointed to by @destination
 *
 *
 * @destination: copy address destination (for the string to copy)
 * @source: the address of the original string to copy
 *
 * Return: the pointer to destination
 *
 */
char *_strcpy(char *destination, char *source)
{
	int sourceCharCounter = 0;
	char currentSourceChar = *source;
	char *nextSourceCharPointer;

	/*
	* we copy until we reach the null terminator '\0'
	* but as we need to include it, we will add it after the while
	*/
	while (currentSourceChar != '\0')
	{
		/*
		* sourceCharCounter begins on 0 so the first address
		* of source is used on the 1st iteration of the while,
		* then we start jumping address positions:
		* 78 + 0, 78 + 1
		*
		*/
		nextSourceCharPointer = (source + sourceCharCounter);
		currentSourceChar = *nextSourceCharPointer;
		*(destination + sourceCharCounter) = currentSourceChar;
		sourceCharCounter++;
	}

	/*
	* sourceCharCounter now lets us jump to the very end of
	* the string we formed, pointed by destination,
	* to add a null Terminator
	*
	*/
	*(destination + sourceCharCounter) = '\0';

	return (destination);
}
