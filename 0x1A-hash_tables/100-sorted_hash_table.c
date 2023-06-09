#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the new hash table, or NULL if it fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into a sorted hash table
 * @ht: The hash table
 * @key: The key string
 * @value: The value string
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *prev;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	prev = NULL;
	node = ht->array[index];

	while (node != NULL && strcmp(node->key, key) < 0)
	{
		prev = node;
		node = node->next;
	}

	if (node != NULL && strcmp(node->key, key) == 0)
	{
		free(node->value);
		node->value = strdup(value);
		return (1);
	}

	node = shash_node_create(key, value);
	if (node == NULL)
		return (0);

	node->next = prev != NULL ? prev->next : ht->array[index];
	if (prev != NULL)
		prev->next = node;
	else
		ht->array[index] = node;

	shash_table_insert_sorted(ht, node);

	return (1);
}

/**
 * shash_table_get - Retrieves a value
 *		associated with a key in a sorted hash table
 * @ht: The hash table
 * @key: The key string
 *
 * Return: The value string, or NULL if the key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in ascending order by key
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->shead;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->snext;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table
 *			in descending order by key
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table and its contents
 * @ht: The hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *node, *prev;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		prev = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = prev;
	}

	free(head->array);
	free(head);
}
