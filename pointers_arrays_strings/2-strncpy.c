#include "main.h"
/**
 * _strncpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Description: This function copies at most @n characters
 * from the string @src to the buffer @dest. If @src is less
 * than @n characters long, the remainder of @dest is padded
 * with null bytes. If @n is 0, nothing is copied.
 *
 * Return: pointer to resulting string @dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
