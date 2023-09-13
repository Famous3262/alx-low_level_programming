#include "search_algos.h"

/**
 * linear_search - A function that searches for a value in an array
 *			of integers using the Linear search algorithm
 *
 * @array: Pointer to the first elements in array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: First index where value is located,
 *	   otherwise, -1 if array is NULL
 */
int linear_search(int *array, size_t size, int value)
{
	int i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < (int)size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);
		if (value == array[i])
			return (i);
	}
	return (-1);
}
