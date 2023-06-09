#include "hash_tables.h"

/**
 * key_index - Gets the index of a key in a hash table.
 * @key: The key to look up.
 * @size: The size of the hash table's array.
 *
 * Return: The index at which the key/value pair should be stored.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);
	return (hash % size);
}
