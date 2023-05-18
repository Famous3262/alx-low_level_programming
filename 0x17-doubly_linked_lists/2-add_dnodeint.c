#include "lists.h"

/**
 * add_dnodeint - Function that adds a new node at the beginning
 * of a dlistint_t list
 * @head: Head of the linked list
 * @n: Value of the element
 *
 * Return: The address of the new element or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->prev = NULL;
	new->next = *head;
	new->n = n;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
