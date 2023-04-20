#include <stdlib.h>
#include <string.h>
#include "substring.h"

#define MAXLEN 1024



int check_word_in_substring(char *str, char **words, int nb_words,
	int word_len, int *matched_words)
{
	int i, j, k;
	int match = 0;

	for (i = 0; i < nb_words; i++)
	{
		match = 0;
		for (j = 0; j < nb_words; j++)
		{
		if (matched_words[j] == 1)
		{
			continue;
		}
		if (strncmp(str + i * word_len, words[j], word_len) == 0)
		{
			match = 1;
			matched_words[j] = 1;
			break;
		}
	}
	if (match == 0)
	{
		break;
	}
}
	for (k = 0; k < nb_words; k++)
	{
		matched_words[k] = 0;
	}
	return (match);
}

/**
 * find_substring - finds all the possible substrings containing all words
 * @s: the string to search in
 * @words: an array of words to search for
 * @nb_words: the number of words in @words
 * @n: a pointer to the number of elements in the resulting array
 *
 * Return: an array of starting indices of @words in @s, NULL on failure
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, l;
	int slen = strlen(s);
	int wlen = strlen(words[0]);
	int match_count = 0;
	int matched_words[MAXLEN] = {0};
	int *result = NULL;

	if (nb_words == 0 || wlen == 0 || slen < nb_words * wlen)
	{
		return (NULL);
	}
	result = malloc(slen * sizeof(int));

	for (i = 0; i <= slen - nb_words * wlen; i++)
	{
		if (check_word_in_substring((char *)(s + i),
		(char **)words, nb_words, wlen, matched_words) == 1)
		{
			result[match_count] = i;
			match_count++;
		}
		for (l = 0; l < MAXLEN; l++)
		{
			matched_words[l] = 0;
		}
	}

	if (match_count == 0)
	{
	return (NULL);
	}
	*n = match_count;
	return (result);
}
