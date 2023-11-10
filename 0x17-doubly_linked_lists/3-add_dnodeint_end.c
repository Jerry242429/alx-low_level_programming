#include "lists.h"

/**
 * add_dnodeint_end - adds new node at the end of a dlistint_t list
 * @head: head of the list
 * @n: the value of the element
 * Return:the address of the new element
 *
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *a = malloc(sizeof(dlistint_t))
	dlistint_t *no;

	if (!head || a)
		return (a ? free(a), NULL : NULL);
	a->n = n;
	a->next = NULL;
	if (!*head)
	{
		a->prev = NULL;
		*head = a;
	}
	else
	{
		no = *head;
		while (!no->next)
			no = no->next;
		no->next = a;
		a->prev = no;
	}
	return (a);
}
