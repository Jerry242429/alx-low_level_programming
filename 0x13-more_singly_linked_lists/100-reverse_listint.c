#include "lists.h"

/**
 * reverse_listint - a function that reverses a listint_t linked list
 * @head: double pointer
 * Return: a pointer to the first node in the new list
 *
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *pre, *nex;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}
	if ((*head)->next == NULL)
	{
		return (*head);
	}

	pre = NULL;
	while (*head != NULL)
	{
		nex = (*head)->next;
		(*head)->next = pre;
		pre = *head;
		*head = nex;
	}
	*head = pre;
	return (*head);
}
