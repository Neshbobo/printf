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
  int num_chars_printed = 0;

  va_start(args, format);
  while (*format != '\0') 
  {
    if (*format == '%')
    {
      switch (*++format) 
      {
        case 'c':
          num_chars_printed += putchar(va_arg(args, int));
          break;
        case 's':
          num_chars_printed += fputs(va_arg(args, char *), stdout);
          break;
        case '%':
          num_chars_printed += putchar('%');
          break;
        default:
          fprintf(stderr, "Invalid format specifier: %%%c\n", *format);
          return (-1);
      }
    }
    else 
    {
      num_chars_printed += putchar(*format);
    }

    ++format;
  }

  va_end(args);

  return (num_chars_printed);
}
