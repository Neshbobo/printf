#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* _printf - Custom printf function supporting %c, %s, and %%
* @format: The format string containing directives
*
* Return: The number of characters printed (excluding the null byte)
*
* Author: Neema and Yatich
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%' && *(format + 1) != '\0')
{
format++; /* Move past the % character */

switch (*format)
{
case 'c':
count += write(1, &va_arg(args, int), 1);
break;

case 's':
count += write(1, va_arg(args, char *), 1);
break;

case '%':
count += write(1, "%", 1);
break;

default:
count += write(1, "%", 1);
count += write(1, format, 1);
break;
}
}
else
{
count += write(1, format, 1);
}

format++;
}

va_end(args);

return (count);
}

/**
* main - Example usage of _printf
*
* Return: Always 0
*/
int main(void)
{
_printf("Hello, %c! This is a %s example. The value of 10%% is %d.\n", 'W', "printf", 10);
return (0);
}
