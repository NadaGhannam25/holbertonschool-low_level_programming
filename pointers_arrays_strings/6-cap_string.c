#include "main.h"
/**
 * cap_string - capitalizes all words of a string
 * @s: pointer to the string
 *
 * Description: This function converts the first character of each
 * word in the string @s to uppercase. Words are separated by
 * the following separators: space, tabulation, new line,
 * ',', ';', '.', '!', '?', '"', '(', ')', '{', '}'.
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;
	int j;
	char separators[] = " \t\n,;.!?\"(){}";

	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] = s[0] - 32;
	}

	while (s[i] != '\0')
	{
		j = 0;
		while (separators[j] != '\0')
		{
			if (s[i] == separators[j])
			{
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] = s[i + 1] - 32;
				}
				break;
			}
			j++;
		}
		i++;
	}

	return (s);
}
