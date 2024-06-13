#include "main.h"

/**
 * print_integer - prints an integer
 * @list: list where integer is to be printed from
 *
 * Return: 0
 */
int print_integer(va_list list)
{
	int value = va_arg(list, int);
	unsigned int neg_value;

	if (value < 0)
	{
		putchar('-');
		/* to take care of large unsigned int values */
		neg_value = value * -1;
		return (1 + int_helper(neg_value));
	}
	return (int_helper(value));
}

/**
 * int_helper - helper function to print integers
 * @value: argument to be printed
 *
 * Return: printed characters
 */
int int_helper(unsigned int value)
{
	unsigned int num = value, count = 0;

	if (value < 9)
	{
		putchar((num % 10) + '0');
		return (1);
	}
	count = 1 + int_helper(value / 10);

	putchar((num % 10) + '0');
	return (count);
}
