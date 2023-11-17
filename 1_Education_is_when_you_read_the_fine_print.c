/**
 *  _printf.cpp
 *
 *  Created on: Nov 15, 2023
 *  Author: Neema and Yatich
 */

#include <stdarg.h>
#include "main.h"

/*
 * _printf: Prints formatted output to the standard output stream.
 *
 * Parameters:
 * format: The format string to use for formatting the output.
 * ...: The arguments to be formatted according to the format string.
 *
 * Returns:
 * The number of characters printed (excluding the null byte used to end output to strings).
 */


int _printf(const char *format, ...) 
{
int count = 0;  // Counter for the number of characters printed
va_list args;  // Variable-argument list for accessing the arguments
va_start(args, format);  // Initialize the variable-argument list

while (*format != '\0') 
{  
if (*format == '%') 
{  
switch (*++format) 
{  
case 'c':  
count += putchar(va_arg(args, int));  // Print the character argument
break;

case 's':  // Handle string format specifier
count += puts(va_arg(args, const char *));  // Print the string argument
break;

case '%':  // Handle literal percent sign
count += putchar('%');  // Print the percent sign
break;

case 'd':  // Handle signed decimal integer format specifier
count += print_decimal(va_arg(args, int));  // Print the integer as a decimal number
break;

case 'i':  // Handle signed decimal integer format specifier (equivalent to 'd')
count += print_decimal(va_arg(args, int));  // Print the integer as a decimal number
break;

default:  // Unrecognized format specifier
count += putchar('%');  // Print the percent sign
count += putchar(*format);  // Print the unrecognized character
break;
}
} 
else 
{  
count += putchar(*format);  // Print the literal character
}

++format;  // Advance to the next character in the format string
}

va_end(args);  // Clean up the variable-argument list
return (count); // Return the number of characters printed
}
