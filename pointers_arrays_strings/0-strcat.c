#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination string (must have enough space)
 * @src: source string to append
 *
 * Description: This function appends the @src string to
 * the @dest string, overwriting the terminating null byte
 * (\0) at the end of @dest, and then adds a terminating
 * null byte at the end.
 *
 * Return: pointer to resulting string @dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* find end of dest */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* append src */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0'; /* add null terminator */

	return (dest);
}
