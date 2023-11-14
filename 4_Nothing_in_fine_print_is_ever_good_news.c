#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * _printf - Custom implementation of printf.
 * @format: Format string containing directives.
 * @...: Variable number of arguments based on the format.
 *
 * This function produces output to stdout according to the given format string.
 * It handles the conversion specifiers 'u', 'o', 'x', and 'X'.
 * It uses a local buffer to minimize the number of calls to the write function.
 *
 * Note: This implementation does not handle flag characters, field width,
 * precision, or length modifiers.
 *
 * Returns: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...) 
{
    va_list args;
    char buffer[BUFFER_SIZE];
    int count = 0;
    int buffer_index = 0;
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
                    buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%u", num);
                    break;
                case 'o':
                    buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%o", num);
                    break;
                case 'x':
                    buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%x", num);
                    break;
                case 'X':
                    buffer_index += snprintf(buffer + buffer_index, BUFFER_SIZE - buffer_index, "%X", num);
                    break;
            }
            format += 2; // Skip the '%u', '%o', '%x', or '%X' in the format string
        } 
		else 
		{
            // Add regular characters to the buffer
            buffer[buffer_index++] = *format;
            format++; // Move to the next character in the format string
        }
	// Check if the buffer is full or the format string is exhausted
        if (buffer_index >= BUFFER_SIZE - 1 || *format == '\0') 
{
		// Add a null terminator to the buffer
		buffer[buffer_index] = '\0';
	// Write the buffer to stdout
            write(1, buffer, buffer_index);
	// Reset the buffer index for the next iteration
            buffer_index = 0;
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
return 0;
}

