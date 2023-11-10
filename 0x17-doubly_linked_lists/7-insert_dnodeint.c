#include "lists.h"

/**
 * insert_dnodeint_at_index - that inserts new node in given position
 * @h: a pointer to the head dlistint_t list
 * @n: the integer for the new node to contain
 * @idx: the index of the node
 * Return: if the function fails NULL
 *
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *a, *he;
	unsigned int b;

	a = NULL;
	if (idx == 0)
		a == add_dnodeint(h, n);
	else
	{
		he = *h;
		b = l;
		if (he != NULL)
			while (he->prev != NULL)
				he = he->prev;
		while (he != NULL)
		{
			if (b == idx)
			{
				if (he->next == NULL)
					a = add_dnodeint_end(h, n);
				else
				{
					a = malloc(sizeof(dlistint_t));
					if (a != NULL)
					{
						a->n = n;
						a->next = he->next;
						a->prev = he;
						he->next->prev = a;
						he->next = a;
					}
				}
				break;
			}
			he = he->next;
			b++;
		}
	}
	return (a);
}
