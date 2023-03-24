#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

void print_char(va_list arg);
void print_int(va_list arg);
void print_float(va_list arg);
void print_string(va_list arg);
void print_all(const char * const format, ...);

/**
 * print_char - this function prints a character.
 * @arg: arguments pointing to the character to be printed.
 */

void print_char(va_list arg)
{
	char letter;

	letter = va_arg(arg, int);
	printf("%c", letter);
}

/**
 * print_int - this function prints an integer.
 * @arg: arguments pointing to the integer to be printed.
 */

void print_int(va_list arg)
{
	int num;

	num = va_arg(arg, int);
	printf("%d", num);
}

/**
 * print_float - this function prints a float.
 * @arg: arguments pointing to the float to be printed.
 */

void print_float(va_list arg)
{
	float num;

	num = va_arg(arg, double);
	printf("%f", num);
}

/**
 * print_string - this function prints a string.
 * @arg: arguments pointing to the string to be printed.
 */

void print_string(va_list arg)
{
	char *str;

	str = va_arg(arg, char *);

	if (str == 0)
	{
		printf("(nil)");
		return;
	}
	printf("%s", str);
}

/**
 * print_all - this function prints anything, followed by a new line.
 * @format: string of characters representing the argument types.
 */

void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *separator = "";

	printer_t funcs[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string}
	};
	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (j < 4 && format[i] != *(funcs[j].symbol))
			j++;

		if (j < 4)
		{
			printf("%s", separator);
			funcs[j].print(args);
			separator = ", ";
		}
		i++;
	}
	printf("\n");

	va_end(args);
}
