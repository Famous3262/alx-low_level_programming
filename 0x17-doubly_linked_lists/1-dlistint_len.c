#include "lists.h"

/**
 * dlistint_len - Function that returns number of elements in a dlistint_t list
 * @h: Points to the head of the linkede list
 *
 * Return: The number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	if (h == NULL)
		return (i);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		i++;
		h = h->next;
	}

	return (i);
}
