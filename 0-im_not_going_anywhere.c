#include "main.h"

/**
* _printf - Prints formatted output to the standard output stream (stdout)
*
* @param format: The format string containing directives specifying the output format
* @param ...: Variadic arguments to be formatted and printed
*
* @return: The number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
int num_printed = 0;
va_list arguments;
va_start(arguments, format);

while (*format)
{
if (*format == '%')
{
switch (*++format)
{
case 'c':
num_printed += _putchar(va_arg(arguments, int));
break;
case 's':
num_printed += _puts(va_arg(arguments, const char *));
break;
case '%':
num_printed += _putchar('%');
break;
default:
// Invalid format specifier, skip it
break;
}
}
else
{
num_printed += _putchar(*format);
}

format++;
}

va_end(arguments);

 return (num_printed);
}
