#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct print_format - struct for printing formatted text to stdout
 * @symbol: the symbol for printing different data types
 * @print: function pointer for printing
 */
typedef struct print_format
{
	char symbol;
	int (*print)(va_list mylist);
} print_ft;

int print_char(va_list list);
int print_str(va_list list);
int print_modulo(va_list list);
int print_integer(va_list list);
int int_helper(unsigned int value);
int _printf(const char *format, ...);

#endif /* MAIN_H */
