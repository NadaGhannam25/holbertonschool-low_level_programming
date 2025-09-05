#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: pointer to the string
 *
 * Description: This function replaces letters in the string with
 * numbers according to 1337 rules:
 * 'a' or 'A' -> '4'
 * 'e' or 'E' -> '3'
 * 'o' or 'O' -> '0'
 * 't' or 'T' -> '7'
 * 'l' or 'L' -> '1'
 *
 * Only one if is used. Two loops maximum. No switch or ternary.
 *
 * Return: pointer to the modified string
 */
char *leet(char *s)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (s[i] == letters[j])
				s[i] = numbers[j];
		}
	}

	return (s);
}
