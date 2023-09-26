#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list.
 * @head:  pointer to the listint_t list to be freed
 */

void free_listint2(listint_t **head)
{
	listint_t *nex;

	if (head == NULL)
	{
		return;
	}
	while (*head == NULL)
	{
		nex = (*head)->next;
		free(*head);
		*head = nex;
	}
}
