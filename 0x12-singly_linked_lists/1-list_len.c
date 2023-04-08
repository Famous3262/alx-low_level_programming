#include <stdio.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the list_t
 * Return: number of elements in the list.
 */

size_t list_len(const list_t *h)
{
	size_t chess = 0;

	while (h != NULL)
	{
		h = h->next;
		chess++;
	}
	return (chess);
}
