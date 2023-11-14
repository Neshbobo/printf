#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Custom implementation of printf.
 * @format: Format string containing directives.
 * @...: Variable number of arguments based on the format.
 *
 * This function produces output to stdout according to the given format string.
 * It handles the conversion specifiers 'c', 's', and '%'.
 * Note: This implementation does not handle flag characters, field width,
 * precision, or length modifiers.
 *
 * Returns: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;
va_start(args, format);
while (*format != '\0') {
        if (*format == '%') {
            format++; // Move to the character after '%'
            switch (*format) {
                case 'c':
                    // Print a character
                    count += putchar(va_arg(args, int));
                    break;
                case 's': {
                    // Print a string
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    // Print a '%' character
                    count += putchar('%');
                    break;
                default:
                    // Unsupported conversion specifier, ignore
                    break;
            }
        } else {
            // Print regular characters
            count += putchar(*format);
        }
format++; // Move to the next character in the format string
    }
va_end(args);
return count;
}
int main() {
    // Example usage of _printf function
    int num = 42;
    const char *str = "World";
int result = _printf("Hello, %c! My number is %d and I love %s%%.\n", 'A', num, str);
printf("Number of characters printed: %d\n", result);
return 0;
}

