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
			i++;
			switch(format[i])
			{
				case 'c':
					
					_putchar((char)va_arg(ap, int));
					contador++;
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
					break;

				case '%':
					_putchar('%');
					contador++;
					break;

				case '\0':
					break;

				default:
					_putchar('%');
					_putchar(format[i]);
					contador =+ 2;
					break;
							
			}


		
		}
	i++;
	}
	printf("%d", contador);
	va_end(ap);
	return (contador);
}
