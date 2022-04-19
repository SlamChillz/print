#include "main.h"

/**
 * number - print number
 *
 * @str: string buffer
 * @num: number
 * @base: number base
 * @size: size of number
 * @precision: precision
 * @type: data type
 * Return: char*
 */
char *number(char *str, long num, int base, int size, int precision, int type)
{
	static const char digits[16] = "0123456789ABCDEF";
	char tmp[66];
	char c, sign, locase;
	int i;

	/* locase = 0 or 0x20. ORing digits or letters with 'locase' */
	/* produces same digits or (maybe lowercased) letters */
	locase = (type & SMALL);
	if (type & LEFT)
		type &= ~ZEROPAD;
	if (base < 2 || base > 16)
		return (NULL);
	c = (type & ZEROPAD) ? '0' : ' ';
	sign = 0;
	checktype(&type, &num, &size, &sign, &base);
	i = 0;
	if (num == 0)
	{
		tmp[i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			tmp[i++] = (digits[(unsigned long) num %
					   (unsigned int) base] | locase);
			num = (unsigned long) num / (unsigned int) base;
		}
	}
	checkprecision(&str, &type, &precision, &i, &size, &sign, &base,
		       &c, &locase);
	while (i < precision--)
		*str++ = '0';
	while (i-- > 0)
		*str++ = tmp[i];
	while (size-- > 0)
		*str++ = ' ';
	return (str);
}
