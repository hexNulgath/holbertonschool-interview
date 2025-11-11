#include "regex.h"

/**
 * regex_match - checks if a string matches a pattern
 * @str: the string to be checked
 * @pattern: the pattern to match; '.' matches any single char
 * and '*' matches any sequence of chars (including empty)
 *
 * Return: 1 if the string matches the pattern, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
    while (*pattern)
    {
        if (*pattern == '*')
        {
            pattern++;
            if (!*pattern)
                return (1);

            while (*str)
            {
                if (regex_match(str, pattern))
                    return (1);
                str++;
            }
            return (0);
        }
        else if (*pattern == '.' || *pattern == *str)
        {
            pattern++;
            str++;
        }
        else
        {
            return (0);
        }
    }

    if (*str)
        return (0);

    return (1);
}