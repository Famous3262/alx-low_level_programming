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
	int jump, left, right;
	int i;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	left = 0;
	right = jump;
	while (right < size && array[right] < value)
	{
		printf("%d\n", array[right]);
		left = right;
		right += jump;
	}
	for (i = left; i <= fmin(right, size - 1); i++)
	{
		printf("%d\n", array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
