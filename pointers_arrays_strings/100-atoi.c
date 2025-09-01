#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: input string
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;
	int digit;
	int found = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		digit = s[i] - '0';
		found = 1;

		if (result < (INT_MIN + digit) / 10)
			return (sign == 1 ? INT_MAX : INT_MIN);

		result = result * 10 - digit;
		i++;
	}

	if (!found)
		return (0);

	if (sign == 1)
	{
		if (result == INT_MIN)
			return (INT_MIN);
		return (-result);
	}
	return (result);
}
