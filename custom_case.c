#include "main.h"

/**
 * r - reverse string
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: string length
 */
void r(char **str, va_list args, int *flags,
int *field_width, int *precision, int *len)
{
	int i, l;
	const char *s;

	s = va_arg(args, char *);
	if (!s)
	{
		*((*str)++) = '%';
		*((*str)++) = 'r';
		return;
	}
	*len = _strnlen(s, *precision);
	l = _strnlen(s, *precision);

	if (!(*flags & LEFT))
	{
		while (*len < (*field_width)--)
			*((*str)++) = ' ';
	}
	for (i = (l - 1); i >= 0; --i)
		*((*str)++) = s[i];
	while (*len < (*field_width)--)
		*((*str)++) = ' ';
}

/**
 * R - rot13 string
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: string length
 */
void R(char **str, va_list args, int *flags,
int *field_width, int *precision, int *len)
{
	int i, j, l;
	const char *s;

	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(args, char *);
	if (!s)
	{
		*((*str)++) = '%';
		*((*str)++) = 'R';
		return;
	}
	*len = _strnlen(s, *precision);
	l = _strnlen(s, *precision);

	if (!(*flags & LEFT))
	{
		while (*len < (*field_width)--)
			*((*str)++) = ' ';
	}
	for (i = 0; i < l; i++)
	{
		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				*((*str)++) = b[j];
				break;
			}
		}
	}
	while (*len < (*field_width)--)
		*((*str)++) = ' ';
}

/**
 * customspecifiers2 - assign functions to indicators
 *
 * @fmt: format
 * @str: string buffer
 * @flags: flags
 * @base: number base
 * Return: int
 */
int customspecifiers2(const char **fmt, char **str, int *flags, int *base)
{
	switch (**fmt)
	{
		case 'b':
			*base = 2;
			return (0);
		case 'o':
			*base = 8;
			return (0);
		case 'x':
			*flags |= SMALL;
			*base = 16;
			return (0);
		case 'X':
			*base = 16;
			return (0);
		case 'd':
		case 'i':
			*flags |= SIGN;
			return (0);
		case 'u':
			return (0);
		default:
			*((*str)++) = '%';
			if (**fmt)
				*((*str)++) = **fmt;
			else
				--(*fmt);
			return (1);
	}
}


