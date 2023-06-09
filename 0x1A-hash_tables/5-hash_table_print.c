#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table.
 * @ht: The hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *temp;
	int fame = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		temp = ht->array[i];
		while (temp != NULL)
		{
			if (!fame)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			fame = 0;
			temp = temp->next;
		}
	}
	printf("}\n");
}
