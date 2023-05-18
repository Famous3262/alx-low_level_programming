#include "lists.h"

/**
 * free_dlistint - Function that frees a dlistint_t list
 * @head: Pointer to the head of the linked list
 *
 * Return: Void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *start;

	if (head != NULL)
		while (head->prev != NULL)
			head = head->prev;

	while ((start = head) != NULL)
	{
		head = head->next;
		free(start);
	}
}
