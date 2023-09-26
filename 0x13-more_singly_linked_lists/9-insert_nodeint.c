#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the first node in the list
 * @idx: index of the node
 * @n: new node value
 * Return: pointer to the ne node or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a;
	listint_t *tempp, *ne;

	if (head == NULL)
	{
		return (NULL);
	}
	if (idx != 0)
	{
		tempp = *head;
		for (a = 0; a < idx - 1 && tempp != NULL; a++)
		{
			tempp = tempp->next;
		}

		if (tempp == NULL)
		{
			return (NULL);
		}
	}
	ne = malloc(sizeof(listint_t));
	if (ne == NULL)
	{
		return (NULL);
	}
	ne->n = n;
	if (idx == 0)
	{
		ne->next = *head;
		*head = ne;
		return (ne);
	}
	ne->next = tempp->next;
	tempp->next = ne;
	return (ne);
}
