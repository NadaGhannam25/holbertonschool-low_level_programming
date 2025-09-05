#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Description: This function compares the string @s1 with
 * the string @s2, character by character. It returns a value
 * less than 0 if @s1 is less than @s2, 0 if they are equal,
 * and greater than 0 if @s1 is greater than @s2.
 *
 * Return: an integer less than, equal to, or greater than 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}
