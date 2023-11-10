#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of
 * a dlistint_t linked list.
 * @head: the head of the list
 * @index: index of the nth node
 * Return: nth node
 *
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int c = 0;

	while (head)
	{
	if (c == index)
		return (head);
	head = head->next;
	c++;
	}
	return (NULL);
}
