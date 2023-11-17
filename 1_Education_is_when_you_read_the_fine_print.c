#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function supporting %d and %i
 * @format: The format string containing directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            format++; /* Move past the % character */
            
            int num = va_arg(args, int);
            char buffer[12]; /* Assumes a 32-bit integer max length */
            int length = sprintf(buffer, "%d", num);
            count += write(1, buffer, length);
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
    _printf("This is an example with %d and %i.\n", 42, -23);
    return (0);
}
