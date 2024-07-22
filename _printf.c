#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

void print_string(char *str, int *contador);
void print_default(const char *format, int *i, int *contador);
void print_numero(int n, int *contador);
/**
 * print_string - Prints a string or "(null)" if the string is NULL.
 * @str: The string to print.
 * @contador: Pointer to the count of characters printed.
 */
void print_string(char *str, int *contador)
{
	int len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		*contador += 6;
	}
	else
	{
		len = _strlen(str);
		write(1, str, len);
		*contador += len;
	}
}
/**
 * print_default - Handles the default case for unsupported format specifiers.
 * @format: The format string.
 * @i: The current index in the format string.
 * @contador: Pointer to the count of characters printed.
 */
void print_default(const char *format, int *i, int *contador)
{
	_putchar(format[*i]);
	*contador += 1;
	_putchar(format[*i + 1]);
}
/**
 * print_numero - Prints an integer as a string.
 * @n: The integer to print.
 * @contador: Pointer to the count of characters printed.
 */

void print_numero(int n, int *contador)
{
	if (n < 0)
	{
		_putchar('-');
		*contador += 1;
		n = -n;
	}
	if (n / 10)
		print_numero(n / 10, contador);
	_putchar((n % 10) + '0');
	*contador += 1;
}
/**
 * _printf - Custom printf function.
 * @format: The format string.
 * @...: The values to format and print.
 * Return: The number of characters printed, or -1 on failure.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	char *str;
	int contador = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			contador++;
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					_putchar((char)va_arg(ap, int));
					contador++;
					i++;
					break;

				case 's':
					str = va_arg(ap, char *);
					print_string(str, &contador);
					i++;
					break;

				case '%':
					_putchar('%');
					contador++;
					i++;
					break;
				case 'i':
				case 'd':
					print_numero(va_arg(ap, int), &contador);
					i++;
					break;
				case '\0':
					contador = -1;
					break;

				default:
					print_default(format, &i, &contador);
					break;
			}
		}
		i++;
	}

	va_end(ap);
	return (contador);
}
