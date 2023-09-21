#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * free_list - release the memory allocated for a list
 *
 * @head: A pointer to the first node of the list of free
 */

void free_list(list_t *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->str)
			free(head->str);
		free(head);
	}
}
