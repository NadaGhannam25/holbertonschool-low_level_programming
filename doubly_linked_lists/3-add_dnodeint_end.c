#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the head of the list
 * @n: constant integer value to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *tail;

	new = malloc(sizeof(*new));
	if (!new)
		return NULL;

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!*head) {
		*head = new;
	} else {
		tail = *head;
		while (tail->next)
			tail = tail->next;

		tail->next = new;
		new->prev = tail;
	}

	return new;
}
