#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function supporting %b
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
        if (*format == '%' && *(format + 1) == 'b')
        {
            format++; /* Move past the % character */
            
            unsigned int num = va_arg(args, unsigned int);
            int bit;
            char buffer[33]; /* Assumes a 32-bit integer */
            buffer[32] = '\0';

            /* Convert the unsigned int to binary */
            for (bit = 31; bit >= 0; bit--)
            {
                buffer[bit] = (num & 1) + '0';
                num >>= 1;
            }

            count += write(1, buffer, 32);
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
    unsigned int value = 42;
    _printf("Binary representation: %b\n", value);
    return (0);
}
