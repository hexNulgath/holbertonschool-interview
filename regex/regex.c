#include <stdio.h>
int regex_match(char const *str, char const *pattern)
{
    while (*pattern) {
        printf("Matching '%c' with '%c'\n", *str, *pattern);
        if (*pattern == '*') {
            pattern++;
            if (!*pattern) {
                return 1; // Match
            }
            while (*str) {
                if (regex_match(str, pattern)) {
                    return 1; // Match
                }
                str++;
            }
            return 0; // No match
        } else if (*pattern == '.' || *pattern == *str) {
            pattern++;
            str++;
        } else {
            return 0; // No match
        }
    }
    if (*str) {
        return 0; // No match
    }
    return 1;
}