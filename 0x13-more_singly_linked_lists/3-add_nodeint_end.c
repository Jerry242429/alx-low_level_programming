#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: head of double pointer
 * @n: int add the list
 * Return: pointer to the new node, or NULL if it fails
 *
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ne;
	listint_t *temp;

	if (head == NULL)
	{
		return (NULL);
	}
	ne = malloc(sizeof(listint_t));
	if (ne == NULL)
	{
		return (NULL);
	}
	ne->n = n;
	ne->next = NULL;
	if (*head == NULL)
	{
		*head = ne;
		return (ne);
	}
	temp = *head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = ne;
	return (ne);
}
