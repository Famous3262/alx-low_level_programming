#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit.
 *
 * Return: 1 if it worked, -1 if an error occured.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int t;

	if (index > 63)
		return (-1);

	t = 1 << index;
	*n = (*n | t);

	return (1);
}
