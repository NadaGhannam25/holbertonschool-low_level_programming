#include "main.h"
/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string (must have enough space)
 * @src: source string to append
 * @n: maximum number of bytes to use from src
 *
 * Description: This function appends the @src string to the @dest string,
 * using at most @n bytes from @src. If @src contains n or more bytes,
 * it does not need to be null-terminated. The resulting string is
 * always null-terminated.
 *
 * Return: pointer to resulting string @dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
