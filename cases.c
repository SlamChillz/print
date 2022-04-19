#include "main.h"

/**
 * c - print character
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 */
void c(char **str, va_list args, int *flags, int *field_width)
{
	if (!(*flags & LEFT))
	{
		while (--*field_width > 0)
			*((*str)++) = ' ';
	}
	*((*str)++) = (unsigned char)va_arg(args, int);
	while (--*field_width > 0)
		*((*str)++) = ' ';
}

/**
 * s - print string
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: string length
 */
void s(char **str, va_list args, int *flags,
int *field_width, int *precision, int *len)
{
	int i;
	const char *s;

	s = va_arg(args, char *);
	*len = _strnlen(s, *precision);

	if (!(*flags & LEFT))
	{
		while (*len < (*field_width)--)
			*((*str)++) = ' ';
	}
	for (i = 0; i < *len; i++)
		*((*str)++) = *s++;
	while (*len < (*field_width)--)
		*((*str)++) = ' ';
}

/**
 * p - print address
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 */
void p(char **str, va_list args, int *field_width, int *flags, int *precision)
{
	if (*field_width == -1)
	{
		*field_width = sizeof(va_arg(args, unsigned long));
		/* *flags |= ZEROPAD; */
		*flags |= SMALL;
		*flags |= SPECIAL;
	}
	*str = number(*str, va_arg(args, unsigned long), 16, *field_width,
		      *precision, *flags);
}

/**
 * lh - length indicators
 *
 * @args: string buffer
 * @flags: flags
 * @qualifier: length specifier
 * @num: integer
 */
void lh(va_list args, int *flags, int *qualifier, unsigned long *num)
{
	if (*qualifier == 'l')
	{
		*num = va_arg(args, unsigned long);
	}
	else if (*qualifier == 'h')
	{
		*num = (unsigned short)va_arg(args, int);
		if (*flags & SIGN)
			*num = (short)*num;
	}
	else if (*flags & SIGN)
	{
		*num = va_arg(args, int);
	}
	else
	{
		*num = va_arg(args, unsigned int);
	}
}

/**
 * customspecifiers1 - assign functions to indicators
 *
 * @fmt: format
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: length
 * Return: int
 */
int customspecifiers1(const char **fmt, char **str, va_list args, int *flags,
		     int *field_width, int *precision, int *len)
{
	switch (**fmt)
	{
	case 'c':
		c(str, args, flags, field_width);
		return (1);
	case 's':
		s(str, args, flags, field_width, precision, len);
		return (1);
	case 'r':
		r(str, args, flags, field_width, precision, len);
		return (1);
	case 'R':
		R(str, args, flags, field_width, precision, len);
		return (1);
	case 'p':
		p(str, args, field_width, flags, precision);
		return (1);
	case '%':
		*((*str)++) = '%';
		return (1);
	default:
		return (0);
	}
}

