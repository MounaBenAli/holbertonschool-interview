#include "holberton.h"

/**
 * wildcmp - compares two strings with a wildcard pattern
 * @s1: first string
 * @s2: second string (may contain * wildcard)
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*s1 == '\0')
			return (0);

		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	if (*s1 == '\0')
		return (*s2 == '\0');
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '\0')
		return (0);
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	return (0);
}
