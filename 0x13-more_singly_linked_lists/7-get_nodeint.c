#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list
 * @head: pointer of the first node
 *
 * @index: index is the index of the node
 * Return: pointer to the node we're looking for, or NULL
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a;

	if (head == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < index; a++)
	{
		head = head->next;
		if (head == NULL)
		{
			return (NULL);
		}
	}
	return (head);
}
