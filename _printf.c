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
	int len;

	if (format == NULL)
		return(-1);

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
						 write(1,"(null)", 6);
						 contador += 6;
						
					}
					else
					{
						len = _strlen(str);
						write(1, str, len);
						contador += len;
					
					}
					i++;
					break;

				case '%':
					_putchar('%');
					contador++;
					break;

				case '\0':
					contador = -1;
					break;

				default:
					_putchar('%');
					_putchar(format[i + 1]);
					contador  =+ 2;
					i++;
					break;
							
			}


		
		}
	i++;
	}
	va_end(ap);
	return (contador);
}
