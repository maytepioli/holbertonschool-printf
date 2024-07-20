#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;
	char *str;
	int contador = 0;

	va_start(ap, format);

	while(format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			contador++;
		}
		else 
		{
			switch(format[i + 1])
			{
				case 'c':
					
					_putchar((char)va_arg(ap, int));
					contador++;
					i++;
					break;

				case 's':
					str = va_arg(ap, char *);
					if (str == NULL)
					{
						contador = write(1,"(null)", 6);
						
					}
					else
					{
						contador = write(1, str, _strlen(str));
					
					}
					i++;
					break;

				case '%':
					_putchar('%');
					contador++;
					i++;
					break;

				case '\0':
					break;

				default:
					_putchar(format[i]);
					i++;
					_putchar(format[i]);
					contador =+ 2;
					break;
							
			}


		
		}
	i++;
	}
	va_end(ap);
	return (contador);
}
