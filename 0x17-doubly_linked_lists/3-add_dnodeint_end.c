#include "lists.h"

/**
 * add_dnodeint_end - Function that adds a new node at the end
 * of a dlistint_t list
 * @head: Head of the linked list
 * @n: Value of the element
 *
 * Return: The address of the new element or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *start;
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	start = *head;

	if (start != NULL)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new;
	}
	else
	{
		*head = new;
	}

	new->prev = start;

	return (new);
}
