#include "lists.h"

/**
 * add_node_end - this function adds a new node at the end
 *		of a linked list
 * @head: pointer to a pointer to the head of the linked list
 * @str: pointer to a null terminated string
 * Return: returns a pointer to the address of the new element
 *		or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	size_t length;
	list_t *new_node, *current_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	for (length = 0; str[length]; length++)
		;
	new_node->len = length;

	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	return (new_node);
}
