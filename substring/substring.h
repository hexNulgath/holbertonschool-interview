#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool find_substring_helper(char const *s, char const **words,
int nb_words, int word_len);

#endif /* SUBSTRING_H */
