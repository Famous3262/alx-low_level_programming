#include "search_algos.h"
#include <math.h>

/**
 * jump_search - A function that searches for a value in a sorted array
 *		of integers using the Jump search algorithm
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: The value to search for
 * Return: First index of where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	int index, j, k, prev;

	if (array == NULL || size == 0)
		return (-1);

	j = (int)sqrt((double)size);
	k = 0;
	prev = index = 0;

	do {
		printf("Value checked array[%d] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
		k++;
		prev = index;
		index = k * j;
	} while (index < (int)size && array[index] < value);

	printf("Value found between indexes [%d] and [%d]\n", prev, index);

	for (; prev <= index && prev < (int)size; prev++)
	{
		printf("Value checked array[%d] = [%d]\n", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}

	return (-1);
}
