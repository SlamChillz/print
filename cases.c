#include "main.h"

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

void s(char **str, va_list args, int *flags, int *field_width, int *precision, int *len)
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

void p(char **str, va_list args, int *field_width, int *flags, int *precision)
{
	if (*field_width == -1)
	{
		*field_width = 2 * sizeof(void *);
		*flags |= ZEROPAD;
	}
	*str = number(*str, (unsigned long) va_arg(args, void *), 16, *field_width, *precision, *flags);
}

void lh(va_list args, int *flags, int *qualifier, unsigned long *num)
{
	if (*qualifier == 'l')
	{
		*num = va_arg(args, unsigned long);
	}
	else if (*qualifier == 'h')
	{
		*num = (unsigned short) va_arg(args, int);
		if (*flags & SIGN)
			*num = (short) *num;
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

int customspecifiers(const char **fmt, char **str, va_list args, int *flags, int *field_width, int *precision, int *len, int *base)
{
	switch (**fmt)
	{
		case 'c':
			c(str, args, flags, field_width);
			return (1);
		case 's':
			s(str, args, flags, field_width, precision, len);
			return (1);
		case 'p':
			p(str, args, field_width, flags, precision);
			return (1);
		case '%':
			*((*str)++) = '%';
			return (1);
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

