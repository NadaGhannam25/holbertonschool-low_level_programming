#include "main.h"

/**
 * leet - Encodes a string into 1337 (leet) speak
 * @str: The input string to be encoded
 *
 * Replaces specific letters with numbers:
 * a/A -> 4, e/E -> 3, o/O -> 0, t/T -> 7, l/L -> 1
 * Uses at most one if statement and two loops
 * No switch statements or ternary operations allowed
 *
 * Return: Pointer to the modified string
 */
char *leet(char *str)
{
    int i;
    char *leet_map = "aA4eE3oO0tT7lL1";

    for (i = 0; str[i] != '\0'; i++)
    {
        int j;

        for (j = 0; leet_map[j] != '\0'; j += 3)
        {
            if (str[i] == leet_map[j] || str[i] == leet_map[j + 1])
                str[i] = leet_map[j + 2];
        }
    }

    return (str);
}
