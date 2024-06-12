#include "main.h"
/**
 * _printf - prints formatted to the stdout just like the printf
 * @format: formatted text to be checked before printing
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	print_ft func[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_modulo},
	};
	va_list list;
	int len = 0, i = 0, j, arr_len = sizeof(func) / sizeof(func[0]);

	va_start(list, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			len++;
		}
		else
		{
			i++;
			for (j = 0; j < arr_len; j++)
			{
				if (format[i] == func[j].symbol)
				{
					len += func[j].print(list);
					break;
				}
			}
			if (format[i] != func[j].symbol)
			{
				i--;
				putchar(format[i]);
				len++;
			}
		}
		i++;
	}
	va_end(list);
	return (len);
}
