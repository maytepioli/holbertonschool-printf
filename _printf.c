#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
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
	int contador;

	va_start(ap, format);

	while(format[i] != '\0')
	
	{
		if (format[i] != '%')
			_putchar(format[i]);
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
						write(1,"(null)", 6);
						contador += 6;
					}
					else
					{
						write(1, str, _strlen(str));
						contador++;
					}
					break;

				case '%':
					_putchar('%');
					contador++;
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
	va_end(ap);
	return (contador);
}
