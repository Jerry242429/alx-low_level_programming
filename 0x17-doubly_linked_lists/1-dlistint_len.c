#include "lists.h"

/**
 * dlistint_len - returns the number of elements in
 * a linked dlistint_t list
 * @h: head of the list
 * Return: size of list
 *
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}
