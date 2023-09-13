#include "search_algos.h"

/**
 * recursive_search - A function that searches for a value in a sorted array
 *			of integers using the Binary search algorithm
 *
 * @array: A pointer to the first element of the array
 * @size: Number of elements in array
 * @value: The value to search for
 * Return: Index of where the value is located or -1 if array is Null
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t mid = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (mid && size % 2 == 0)
		mid--;

	if (value == array[mid])
		return ((int)mid);

	if (value < array[mid])
		return (recursive_search(array, mid, value));

	mid++;

	return (recursive_search(array + mid, size - mid, value) + mid);
}

/**
 * binary_search - calls to binary_search to return
 *			the index of the number
 *
 * @array: Pointer to the first element in the array
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, otherwise -1 if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	int index;

	index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
