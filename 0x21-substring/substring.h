#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int check_word_in_substring(char *str, char **words, int nb_words,
int word_len, int *matched_words);

#endif /* SUBSTRING_H */

