#include "main.h"

/**
 * _puts - prints a string, followed by a new line,
 * @str: pointer to the string to print
 * Return: the length of the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_purchar(str[i]);
		i++;
	}
	_purchar('\n');
}
