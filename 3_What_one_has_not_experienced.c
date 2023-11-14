#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom implementation of printf.
 * @format: Format string containing directives.
 * @...: Variable number of arguments based on the format.
 *
 * This function produces output to stdout according to the given format string.
 * It handles the conversion specifiers 'u', 'o', 'x', and 'X'.
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
        if (*format == '%' && (*(format + 1) == 'u' || *(format + 1) == 'o' ||
                                 *(format + 1) == 'x' || *(format + 1) == 'X')) 
	{
            // Print an unsigned integer in the specified format
            unsigned int num = va_arg(args, unsigned int);
            switch (*(format + 1)) 
			{
                case 'u':
                    count += printf("%u", num);
                    break;
                case 'o':
                    count += printf("%o", num);
                    break;
                case 'x':
                    count += printf("%x", num);
                    break;
                case 'X':
                    count += printf("%X", num);
                    break;
			}
            format += 2; // Skip the '%u', '%o', '%x', or '%X' in the format string
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
int main() 
{
    // Example usage of _printf function
    unsigned int unsignedNum = 123;
    unsigned int octalNum = 77;
    unsigned int hexNum = 255;
int result = _printf("Unsigned: %u, Octal: %o, Lowercase Hex: %x, Uppercase Hex: %X.\n",
                         unsignedNum, octalNum, hexNum, hexNum);
printf("Number of characters printed: %d\n", result);
Return (0);
}
