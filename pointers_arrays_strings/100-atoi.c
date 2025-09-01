#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int _atoi(char *s)
{
    int i = 0;
    int sign = 1;
    unsigned int num = 0;
    int found_digit = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '-')
            sign *= -1;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            found_digit = 1;
            num = (num * 10) + (s[i] - '0');
        }
        else if (found_digit)
            break;
        i++;
    }

    return (sign * (int)num);
}
