#include "search_algos.h"

/**
 * linear_search - A function that searches for a value in an array
 *		of integers using the Linear search algorithm
 *
 * @array: Pointer to the first elements in array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: EXIT_SUCCESS
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Comparing %d\n", array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
