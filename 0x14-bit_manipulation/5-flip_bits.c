#include "main.h"

/**
 * flip_bits - returns num of bits you would need to flip
 * to get from one num to another.
 * @n: num one.
 * @m: num two.
 *
 * Return: num of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int knight;

	for (knight = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			knight++;
	}

	return (knight);
}
