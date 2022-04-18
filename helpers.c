#include "main.h"

/**
 * utchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - print a string
 * @s: string parameter
 * Description: a function that prints a string, followed
 * by a new line, to stdout.
 *
 * Return: None
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	/* _putchar('\n'); */
}

/**
 * _isdigit - check for digits
 * @c: char variable
 * Description: a function that check if c a number
 *
 * Return: 1 if number, else 0
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * _strnlen - get the length of string to print
 * @s: pointer to string
 * @maxlen: limit length, integer
 *
 * Return: size_t
 */
size_t _strnlen(const char *s, size_t maxlen)
{
	size_t len;

	for (len  = 0; len < maxlen; len++, s++)
	{
		if (!*s)
			break;
	}
	return (len);
}

/**
 * skip_atoi - get number from charaters
 * @s: pointer to a pointer to a char
 *
 * Return: integer
 */
int skip_atoi(const char **s)
{
	int i = 0;

	while (_isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return i;
}

