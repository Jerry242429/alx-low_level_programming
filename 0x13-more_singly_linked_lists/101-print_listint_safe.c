#include "lists.h"

/**
 * _r - reallocate memory for an array of pointers
 * @list: the old list to append
 * @size: size of the new lists
 * @new: new node to add to the list
 * Return: pointer to the new list
 *
 */

const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **newstlist;
	size_t a;

	newstlist = malloc(size * sizeof(listint_t *));
	if (newstlist == NULL)
	{
		free(list);
		exit(98);
	}
	for (a = 0; a < size - 1; a++)
	{
		newstlist[a] = list[a];
	}
	newstlist[a] = new;
	free(list);
	return (newstlist);
}

/**
 * print_listint_safe - a function that prints a listint_t
 * @head: pointer to the start of the list
 * Return: the number of nodes in the list
 *
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t a, number = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (a = 0; a < number; a++)
		{
			if (head == list[a])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (number);
			}
		}
		number++;
		list = _r(list, number, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (number);
}
