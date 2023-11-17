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
        if (*format == '%' && *(format + 1) != '\0')
        {
            format++; /* Move past the % character */

            switch (*format)
            {
                case 'c':
                {
                        char c = va_arg(args, int);
                        count += write(1, &c, 1);
                    }
                   
                    break;

                case 's':
                    count += write(1, va_arg(args, char *), 1);
                    break;

                case 'd':
                case 'i':
                    {
                        int num = va_arg(args, int);
                        char buffer[12]; /* Assumes a 32-bit integer max length */
                        int length = sprintf(buffer, "%d", num);
                        count += write(1, buffer, length);
                    }
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
    _printf("Hello, %c! This is a %s example. The value of %d is %i.\n", 'W', "printf", 10, -20);
    return (0);
}
