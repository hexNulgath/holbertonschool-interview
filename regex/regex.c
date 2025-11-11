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
	if (*pattern == '\0')
		return (*str == '\0');

	int has_star = (*(pattern + 1) == '*');

	if (has_star)
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return (regex_match(str + 1, pattern));

		return (0);
	}
	else
	{
		if (*str != '\0' && (*pattern == '.' || *pattern == *str))
			return (regex_match(str + 1, pattern + 1));

		return (0);
	}
}
