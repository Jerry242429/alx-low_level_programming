#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of a listint_t
 * @head: double pointer
 * @index: index of node
 * Return: 1 (Success), or -1 (Fail)
 *
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int a;
	listint_t *ten, *nex;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		nex = (*head)->next;
		free(*head);
		*head = nex;
		return (1);
	}
	ten = *head;
	for (a = 0; a < index - 1; a++)
	{
		if (ten->next == NULL)
			return (-1);
		ten = ten->next;
	}
	nex = ten->next;
	ten->next = nex->next;
	free(nex);
	return (1);
}
