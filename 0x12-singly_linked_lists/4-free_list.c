#include "lists.h"

/**
 * free_list - this function frees a list
 * @head: pointer to the head node in list_t
 */
void free_list(list_t *head)
{
	list_t *tmp, *node = head;

	while (node != NULL)
	{
		tmp = node;

		node = node->next;

		free(tmp->str);
		free(tmp);
	}
}
