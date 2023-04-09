#include <stdlib.h>
#include "lists.h"
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: head of the linked list.
 * @str: string to be stored in the new node
 * Return: the address of the new element or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t ply;
	size_t flu;

	ply = malloc(sizeof(list_t));
	if (ply == NULL)
		return (NULL);

	ply->str = strdup(str);

	for (flu = 0; str[flu]; flu++)
		;
	ply->len = flu;
	ply->next = *head;
	*head = ply;

	return (*ply);
}
