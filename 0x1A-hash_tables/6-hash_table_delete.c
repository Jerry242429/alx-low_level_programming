#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: A pointer
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *tmp;
	hash_table_t *head = t;
	unsigned long int i;

	for (i = 0; i < t->size; i++)
	{
		if (t->array[i] != NULL)
		{
			node = t->array[i];
			while (node != NULL)
			{
				tmp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = tmp;
			}
		}
	}
	free(head->array);
	free(head);
}
