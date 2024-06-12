#include "main.h"

/**
 * print_char - prints a character to the stdout
 * @list: list to print a character from
 * Return: 1
 */
int print_char(va_list list)
{
	putchar(va_arg(list, int));
	return (1);
}

/**
 * print_str - prints a string to the stdout
 * @list: list to print a string from
 * Return: the number of characters printed
 */
int print_str(va_list list)
{
	char *s = va_arg(list, char *);
	int i = 0;

	if (!s)
		s = "(null)";

	while (s[i])
	{
		putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * print_modulo - prints the percent sign to the stdout
 * @list: list to print the percent sign from (unused)
 * Return: 1
 */
int print_modulo(va_list list)
{
	(void)list;
	putchar('%');
	return (1);
}
