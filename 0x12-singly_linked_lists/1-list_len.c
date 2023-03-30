#include "lists.h"

/**
 * list_len - function returns the numbers of elements
 *		in a linked list
 * @h: pointer to the head of the linked list list_t
 * Return: returns numelements.
 */
size_t list_len(const list_t *h)
{
	size_t num_elems = 0;

	while (h != NULL)
	{
		num_elems++;
		h = h->next;
	}
	return (num_elems);
}
