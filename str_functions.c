#include "monty.h"
/**
 * _custom_strcmp - Function that compares two strings.
 * @s1: type 1 str compared
 * @s2: type 2 str compared
 * Return: 0 if s1 and s2 are equals.
 *         another value if they are different
 */
int _custom_strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sfch - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sfch(char *s, char c)
{
	int cur_line = 0;

	while (s[cur_line] != '\0')
	{
		if (s[cur_line] == c)
		{
			break;
		}
		cur_line++;
	}
	if (s[cur_line] == c)
		return (1);
	else
		return (0);
}

/**
 * _custom_strtok - function that cut a string into tokens depending of the delimiter
 * @s: string to be cut into parts
 * @d: delimiters
 * Return: first partition
 */
char *_custom_strtok(char *s, char *d)
{
	static char *ultimate;
	int i = 0, j = 0;

	if (!s)
		s = ultimate;
	while (s[i] != '\0')
	{
		if (_sfch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimate = s + i + 1;
			*ultimate = '\0';
			s = s + j;
			return (s);
		}
		else if (_sfch(d, s[i]) == 0 && _sfch(d, s[i + 1]) == 0)
			i++;
		else if (_sfch(d, s[i]) == 0 && _sfch(d, s[i + 1]) == 1)
		{
			ultimate = s + i + 1;
			*ultimate = '\0';
			ultimate++;
			s = s + j;
			return (s);
		}
		else if (_sfch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
