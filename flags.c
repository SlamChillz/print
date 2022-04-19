#include "main.h"

/**
 * checktype - check data type
 *
 * @type: data type
 * @num: number
 * @size: size
 * @sign: polarity
 * @base: number base
 */
void checktype(int *type, long *num, int *size, char *sign, int *base)
{
	if (*type & SIGN)
	{
		if (*num < 0)
		{
			*sign = '-';
			*num = -(*num);
			(*size)--;
		}
		else if (*type & PLUS)
		{
			*sign = '+';
			(*size)--;
		}
		else if (*type & SPACE)
		{
			*sign = ' ';
			(*size)--;
		}
	}
	if (*type & SPECIAL)
	{
		if (*base == 16)
			*size -= 2;
		else if (*base == 8)
			(*size)--;
	}
}

/**
 * checkprecision - check number precision
 *
 * @str: string buffer
 * @type: data type
 * @precision: precision vaalue
 * @i: index
 * @size: size
 * @sign: polarity
 * @base: number base
 * @c: character operand
 * @locase: locase
 */
void checkprecision(char **str, int *type, int *precision,
int *i, int *size, char *sign, int *base, char *c, char *locase)
{
	if (*i > *precision)
		*precision = *i;
	*size -= *precision;

	if (!(*type & (ZEROPAD + LEFT)))
	{
		while ((*size)-- > 0)
			*((*str)++) = ' ';
	}
	if (*sign)
		*((*str)++) = *sign;
	if (*type & SPECIAL)
	{
		if (*base == 8)
		{
			*((*str)++) = '0';
		}
		else if (*base == 16)
		{
			*((*str)++) = '0';
			*((*str)++) = ('X' | *locase);
		}
	}
	if (!(*type & LEFT))
	{
		while ((*size)-- > 0)
			*((*str)++) = *c;
	}
}
