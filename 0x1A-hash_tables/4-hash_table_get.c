#include "hash_tables.h"

/**
 * hash_table_get - value associated with a key in a hash table returned
 * @ht: A pointer.
 * @key: The key to get the value of.
 * Return: Null
 *   
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i = 0;
	hash_node_t  *b;

	if (!ht || !key || !*key)
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	b = ht->array[i];

	while (b)
	{
		if (!strcmp(key, b->key))
			return (b->value);
		b = b->next;
	}
	return (NULL);
}
