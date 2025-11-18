/*
 * Description: functions to find all indices where a concatenation of the
 *              provided words appears in a string.
 */

#include "substring.h"

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	const char *s_start;
	int i, j, new_size, *arr, word_len;
	bool found;

	word_len = strlen(words[0]);
	s_start = s;
	*n = 0;
	arr = malloc(10000 * sizeof(int));
	while (*s != '\0')
	{
		found = false;
		for (i = 0; i < nb_words; i++)
		{
			const char *word = words[i];
			char const **helper = NULL;

			if (strncmp(s, word, word_len) == 0)
			{
				helper = malloc((nb_words - 1) * sizeof(char *));
				if (helper == NULL)
					continue;

				new_size = 0;
				for (j = 0; j < nb_words; j++)
				{
					if (j != i)
						helper[new_size++] = words[j];
				}
				if (find_substring_helper(s + word_len, helper, new_size, word_len))
					found = true;
				free((void *)helper);
				if (found)
					break;
			}
		}
		if (found)
			arr[(*n)++] = s - s_start;
		s++;
	}
	return (arr);
}

bool find_substring_helper(char const *s, char const **words, int nb_words,
						   int word_len)
{
	int i, j, new_size;
	char const **helper = NULL;

	if (nb_words == 0)
		return (true);

	for (i = 0; i < nb_words; i++)
	{
		const char *word = words[i];

		if (strncmp(s, word, word_len) == 0)
		{
			helper = malloc((nb_words - 1) * sizeof(char *));
			if (helper == NULL)
				return (false);

			new_size = 0;
			for (j = 0; j < nb_words; j++)
			{
				if (j != i)
					helper[new_size++] = words[j];
			}

			if (find_substring_helper(s + word_len, helper, new_size, word_len))
			{
				free((void *)helper);
				return (true);
			}

			free((void *)helper);
		}
	}

	return (false);
}
