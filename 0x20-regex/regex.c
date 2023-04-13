#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 *
 * @str: string to be scanned
 * @pattern: regular expression
 * Return: 1 if the pattern matches the string, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	const char *s = str;
	const char *p = pattern;
	char prev_char = 0;

	while (*p || prev_char == '*')
	{
	if (*p == '.')
	{
		prev_char = '.';
		p++;
		s++;
	}
	else if (*p == '*')
	{
	while (*s == prev_char || prev_char == '.')
	{
		s++;
		if (*s == '\0')
		break;
	}
		p++;
	}
		else if (*p == *s)
		{
			prev_char = *p;
			p++;
			s++;
		}
		else if (prev_char != '*')
		{
			return (0);
		}
		else
		{
			s++;
		}
	}
	return ((*s == '\0' && *p == '\0'));
}
