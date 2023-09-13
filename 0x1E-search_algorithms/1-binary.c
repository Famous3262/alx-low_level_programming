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
	int start, mid, end;
	int i;

	if (array == NULL)
		return (-1);

	start = 0;
	end = size - 1;

	while (start <= end)
	{
		mid = i(start + end) / 2;
		printf("Searching subarray: ");

		for (i = start; i <= end; i++)
			printf("%d ", array[i]);

		printf("\n");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}
