#include "lists.h"

/**
 * delete_dnodeint_at_index - a function that deletes the node at
 * index index of a dlistint_t linked list
 * @head: the head of the list
 * @index:  the node that should be deleted
 * Return: 1 if it succeeded, -1 if it failed
 *
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *t = *head;

	if (*head == NULL)
		return (-1);
	for (; index != 0; index--)
	{
		if (t == NULL)
			return (-1);
		t = t->next;
	}
	if (t == *head)
	{
		*head = t->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		t->prev->next = t->next;
		if (t->next != NULL)
			t->next->prev = t->prev;
	}
	free(t);
	return (1);
}
