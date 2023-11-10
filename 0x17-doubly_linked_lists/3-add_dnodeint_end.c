#include "lists.h"

/**
 * add_dnodeint_end - adds new node at the end of a dlistint_t list
 * @head: head of the list
 * @n: the value of the element
 * Return: the address of the new element
 *
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *a, *la;

	a = malloc(sizeof(dlistint_t));
	if (a == NULL)
		return (NULL);

	a->n = n;

	a->next = NULL;

	la = *head;

	if (*head == NULL)
	{
		a->next = *head;
		*head = a;
	}
	else
	{
		while (la->next)
			la = la->next;
		la->next = a;
	}
	a->prev = la;

	return (a);
}
