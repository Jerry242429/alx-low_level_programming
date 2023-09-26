#include "lists.h"

/**
 * print_listint - a function prints all the elements of a linked list
 *
 * @h: head of link list node
 *
 * Return: number of nodes
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t a = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		a++;
		h = h->next;
	}
	return (a);
}
