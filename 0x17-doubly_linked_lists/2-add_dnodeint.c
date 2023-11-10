#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a dlistint_t list
 * @head: head of the list
 * @n: the value of the element
 * Return: the address of the new element
 *
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *b;
	dlistint_t *a = malloc(sizeof(dlistint_t));

	if (a == NULL)
		return (NULL);
	a->n = n;
	a->prev = NULL;
	b = *head;

	if (b != NULL)
	{
		while (b->prev != NULL)
			b = b->prev;
	}
	a->next = b;

	if (b != NULL)
		b->prev = a;
	*head = a;
	return (a);
}
