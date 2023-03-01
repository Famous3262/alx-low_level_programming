#include "main.h"

/**
 * _puts - print a string to the stdout
 * @str: the string
 * Return: the length of the string
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_purchar(str[i]);
		i++;
	}
	_purchar('\n');
}
