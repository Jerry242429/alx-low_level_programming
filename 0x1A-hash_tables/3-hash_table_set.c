#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table.
 * @ht: pointer the hash table.
 * @key: The key.
 * @value: value
 * Return: 1 or 0
 *
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	char *vcopy, *kcopy;
	unsigned long int i = 0;
	hash_node_t  *bucket, *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
                return (0);

	vcopy = strdup(value);
	if (vcopy == NULL)
                return (0);

	i = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[index];

	while (bucket)
	{
		if (!strcmp(key, bucket->key))
		{
			free(bucket->value);
			bucket->value = vcopy;
			return (1);
		}
		bucket = bucket->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(vcopy);
		return (0);
	}
	kcopy = strdup(key);
	if (!kcopy)
		return (0);
	new_node->key = kcopy;
	new_node->value = vcopy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
