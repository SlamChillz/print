#ifndef PRINTF
#define PRINTF
#define ZEROPAD 1  /* pad with zero */
#define SIGN 2	   /* unsigned/signed long */
#define PLUS 4	   /* show plus */
#define SPACE 8	   /* space if plus */
#define LEFT 16	   /* left justified */
#define SMALL 32   /* Must be 32 == 0x20 */
#define SPECIAL 64 /* 0x */

#include <unistd.h>
#include <stdarg.h>
/* #include <string.h> */

int _printf(const char *fmt, ...);
int _putchar(char c);
void _puts(char *s);
int _isdigit(char c);
int skip_atoi(const char **s);
size_t _strnlen(const char *s, size_t maxlen);
void getflags(const char **fmt, int *flags);
void getwidth(const char **fmt, va_list args, int *field_width, int *flags);
void getprecision(const char **fmt, va_list args, int *precision);
void getqualifier(const char **fmt, int *qualifier);
void c(char **str, va_list args, int *flags, int *field_width);
void s(char **str, va_list args, int *flags, int *field_width, int *precision, int *len);
void r(char **str, va_list args, int *flags, int *field_width, int *precision, int *len);
void R(char **str, va_list args, int *flags, int *field_width, int *precision, int *len);
void p(char **str, va_list args, int *field_width, int *flags, int *precision);
void lh(va_list args, int *flags, int *qualifier, unsigned long *num);
char *number(char *str, long num, int base, int size, int precision, int type);
void checktype(int *type, long *num, int *size, char *sign, int *base);
void checkprecision(char **str, int *type, int *precision, int *i, int *size, char *sign, int *base, char *c, char *locase);
int customspecifiers1(const char **fmt, char **str, va_list args, int *flags, int *field_width, int *precision, int *len);
int customspecifiers2(const char **fmt, char **str, int *flags, int *base);

#endif /* PRINTF */
