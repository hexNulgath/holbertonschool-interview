#include "substring.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool find_substring_helper(char const *s, char const **words, int nb_words, int word_len);

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len = strlen(words[0]);
	const char *s_start = s;

	*n = 0;
	int *arr = malloc(10000 * sizeof(int));

	while (*s != '\0') {

		bool found = false;

		for (int i = 0; i < nb_words; i++) {
			const char *word = words[i];

			if (strncmp(s, word, word_len) == 0) {
				char const *helper[nb_words - 1];
				int new_size = 0;

				for (int j = 0; j < nb_words; j++) {
					if (j != i) {
						helper[new_size++] = words[j];
					}
				}

				if (find_substring_helper(s + word_len, helper, new_size, word_len)) {
					found = true;
					break;
				}
			}
		}

		if (found) {
			arr[(*n)++] = s - s_start;
		}

		s++;
	}

	return arr;
}

bool find_substring_helper(char const *s, char const **words, int nb_words, int word_len)
{
	if (nb_words == 0)
		return true;

	for (int i = 0; i < nb_words; i++) {

		const char *word = words[i];

		if (strncmp(s, word, word_len) == 0) {

			char const *helper[nb_words - 1];
			int new_size = 0;

			for (int j = 0; j < nb_words; j++) {
				if (j != i)
					helper[new_size++] = words[j];
			}

			if (find_substring_helper(s + word_len, helper, new_size, word_len))
				return true;
		}
	}

	return false;
}
