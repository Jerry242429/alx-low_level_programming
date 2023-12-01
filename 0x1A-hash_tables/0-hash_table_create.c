/*
 * File: 0-hash_table_create.c
 * Auth: Gedeon Obae Gekonge
 */

#include "hash_tables.h"

/**
 * hash_table_create - a function that Creates a hash table.
 * @size: array size.
 *
 * Return: If an error occurs - NULL.
 * 
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *t;

	t = malloc(sizeof(hash_table_t));
	if (t == NULL)
		return (NULL);

	t->size = size;
	t->array = malloc(sizeof(hash_node_t *) * size);
	if (t->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		t->array[i] = NULL;

	return (t);
}
