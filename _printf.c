#include "main.h"

/**
 * _printf - prints formatted to the stdout just like the printf
 * @format: formatted text to be checked before printing
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int flag = 0, len = 0, i = 0, j, arr_len;
	print_ft func[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_modulo},
		{'d', print_integer},
		{'i', print_integer},
	};

	/* check if format == NULL or if (format == '%' && '\0') */
	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] != '%') /* if format is normal strings all through */
			putchar(format[i]), len++;
		else /* if a '%' sign is found, increment and check the next character*/
		{
			j = 0, i++;
			arr_len = sizeof(func) / sizeof(func[0]);
			while (j < arr_len)
			{
				if (format[i] == func[j].symbol)
				{
					len += func[j].print(list);
					flag = 1; /* indicates a match was found*/
					break;
				} j++;
			}
			if (flag == 0) /* if a match was not found, decrement and print format[i] */
				putchar(format[--i]), len++;
		} i++;
	}

	va_end(list);
	return (len);
}
