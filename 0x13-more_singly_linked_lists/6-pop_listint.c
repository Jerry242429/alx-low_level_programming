#include "lists.h"

/**
 * pop_listint -  deletes the head node of a listint_t linked list
 * @head: pointer to the first element in the linked list
 * Return: empty
 *
 */

int pop_listint(listint_t **head)
{
	listint_t *next;
	int a;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}
	next = *head;
	*head = next->next;
	a = next->n;
	free(next);
	return (a);
}
