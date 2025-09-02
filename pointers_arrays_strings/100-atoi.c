#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string, or 0 if none
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	int result = 0;
	int found_digit = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int digit = s[i] - '0';
			found_digit = 1;

			/* check overflow before multiplying/adding */
			if (sign == 1 && (result > (INT_MAX - digit) / 10))
				return (INT_MAX);
			if (sign == -1 && (result > (INT_MIN + digit) / -10))
				return (INT_MIN);

			result = result * 10 + digit;
		}
		else if (found_digit)
			break;
		i++;
	}

	return (result * sign);
}
