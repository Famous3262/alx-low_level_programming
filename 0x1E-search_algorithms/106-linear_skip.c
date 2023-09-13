#include "search_algos.h"

/**
 * linear_skip - Function that searches for a value
 *		in a sorted skip list of integers
 *
 * @list: Pointer to the head of the skip list
 * @value: Value to search for
 * Return: Pointer to the first node where value is located
 *		Otherwise NULL if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp;

	if (list == NULL)
		return (NULL);

	tmp = list;

	do {
		list = tmp;
		tmp = tmp->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)tmp->index, tmp->n);
	} while (tmp->express && tmp->n < value);

	if (tmp->express == NULL)
	{
		list = tmp;
		while (tmp->next)
			tmp = tmp->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)tmp->index);

	while (list != tmp->next)
	{
		printf("Value checked at index [%d] = [%d]\n",
			(int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
