#include "main.h"

/**
 * print_alphabet_x10 - print 10 times the alphabet in lower case
 */

void print_alphabet_x10(void)
{
	int i = 0;
	char j;

	while (i++ <= 9)
	{
		for (j = 'a'; j <= 'z'; j++)
			_putchar(j);
		_putchar('\n');
	}
}
