#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom implementation of printf.
 * @format: Format string containing directives.
 * @...: Variable number of arguments based on the format.
 *
 * This function produces output to stdout according to the given format string.
 * It handles the conversion specifiers 'd' and 'i'.
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
while (*format != '\0') {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) 
	{
            // Print an integer
            int num = va_arg(args, int);
            count += printf("%d", num);
            format += 2; // Skip the '%d' or '%i' in the format strin
	} 
	else 
{
            // Print regular characters
            count += putchar(*format);
            format++; // Move to the next character in the format string//
}
    }
va_end(args);
return count;
}
int main() {
    // Example usage of _printf function
    int num = 42;
int result = _printf("My number is %d and %i is another representation.\n", num, num);
printf("Number of characters printed: %d\n", result);
return 0;
}
