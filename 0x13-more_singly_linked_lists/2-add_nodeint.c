#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: head of double pointer
 * @n: int add the list
 *
 * Return: pointer to the new node, or NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *tr;

	if (head == NULL)
	{
		return (NULL);
	}
	tr = malloc(sizeof(listint_t));
	if (tr == NULL)
	{
		return (NULL);
	}
	tr->n = n;
	tr->next = *head;
	*head = tr;
	return (tr);
}
