#include "hash_tables.h"
/**
 * key_index - Get the index stored in array of a hash table.
 * @key: to get the index of hash table.
 * @size: size .
 *
 * Return: Index of the key.
 *
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
