#include "main.h"

/**
 * _printf - writes formatted text to the stdout
 * @format: character, string, or formatted text
 *
 * Return: number of bytes of format
 */

int _printf(const char *format, ...)
{
	int obi = 0;
	char b;
	char *uncleTed;
	va_list hufano;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(hufano, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			obi++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			else if (*format == '%')
			{
				write(1, format, 1);
				obi++;
			}
			if (*format == 'c')
			{
				b = va_arg(hufano, int);
				write(1, &b, 1);
			}
			else if (*format == 's')
			{
				uncleTed = va_arg(hufano, char *);
				write(1, uncleTed, lengthOfStr(uncleTed));
				obi += lengthOfStr(uncleTed);
			}
		}
		format++;
	}
	va_end(hufano);
	return (obi);
}
