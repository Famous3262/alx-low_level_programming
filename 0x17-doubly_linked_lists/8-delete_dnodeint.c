#include "lists.h"

/**
 * delete_dnodeint_at_index - Function that deletes the node at index
 * of a dlistint_t linked list
 * @head: Head of the list
 * @index: Index of the new node
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *start;
	dlistint_t *a;
	unsigned int j;

	start = *head;

	if (start != NULL)
		while (start->prev != NULL)
			start = start->prev;

	j = 0;

	while (start != NULL)
	{
		if (j == index)
		{
			if (j == 0)
			{
				*head = start->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				a->next = start->next;

				if (start->next != NULL)
					start->next->prev = a;
			}

			free(start);
			return (1);
		}
		a = start;
		start = start->next;
		j++;
	}

	return (-1);
}
