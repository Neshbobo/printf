#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom implementation of printf.
 * @format: Format string containing directives.
 * @...: Variable number of arguments based on the format.
 *
 * This function produces output to stdout according to the given format string.
 * It handles the conversion specifiers 'd', 'i', and 'b'.
 * - 'd' and 'i' are for printing integers.
 * - 'b' is a custom specifier to print an unsigned integer in binary.
 *
 * Note: This implementation does not handle flag characters, field width,
 * precision, or length modifiers.
 *
 * Returns: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...) 
{
    va_list args;
    int count = 0;
va_start(args, format);
while (*format != '\0') 
	{
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) 
		{
            // Print an integer
            int num = va_arg(args, int);
            count += printf("%d", num);
            format += 2; // Skip the '%d' or '%i' in the format string
        } else if (*format == '%' && *(format + 1) == 'b') 
		{
            // Print an unsigned integer in binary
            unsigned int num = va_arg(args, unsigned int);
            count += print_binary(num);
            format += 2; // Skip the '%b' in the format string
		}
			else 
		{
            // Print regular characters
            count += putchar(*format);
            format++; // Move to the next character in the format string
		}
	}
va_end(args);
return count;
}
/**
 * print_binary - Print an unsigned integer in binary.
 * @num: The unsigned integer to be printed.
 *
 * This function prints an unsigned integer in binary format.
 * Note: This implementation does not handle formatting options.
 *
 * Returns: The number of characters printed.
 */
int print_binary(unsigned int num) 
{
    int count = 0;
    if (num > 1) {
        count += print_binary(num / 2);
	}
    count += putchar('0' + num % 2);
    return count;
}
int main() 
{
    // Example usage of _printf function
    int num = 42;
    unsigned int binaryNum = 73;
int result = _printf("My number is %d. In binary, it is %b.\n", num, binaryNum);
printf("Number of characters printed: %d\n", result);
 
result(0);
}

