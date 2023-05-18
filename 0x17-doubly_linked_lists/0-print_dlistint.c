#include "lists.h"

/**
 * print_dlistint - This function prints all elements of a dlistint_t list
 * @h: points to the head of the doubly linked list
 *
 * Return: Number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int j = 0;

	if (h == NULL)
		return (j);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		j++;
		h = h->next;
	}

	return (j);
}
