#include "search_algos.h"

/**
 * rec_search - Function that searches for a value
 *		 in a sorted array of integers
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index where value is located otherwise, -1 if array is NULL
 */
int rec_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	size_t low = size / 2;
	size_t j;

	printf("Searching in array");

	for (j = 0; j < size; j++)
		printf("%s %d", (j == 0) ? ":" : ",", array[j]);

	printf("\n");

	if (low && size % 2 == 0)
		low--;

	if (value == array[low])
	{
		if (low > 0)
			return (rec_search(array, low + 1, value));
		return ((int)low);
	}

	if (value < array[low])
		return (rec_search(array, low + 1, value));

	low++;
	return (rec_search(array + low, size - low, value) + low);
}

/**
 * advanced_binary - Function that calls to rec_search
 *			to return the index of the number
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index of where the value is located, otherwise -1 if array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	int index;

	index = rec_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
