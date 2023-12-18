#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forw, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	for (forw = (*list)->next; forw && forw->prev; forw = forw->next)
	{
	for (; forw && forw->prev && forw->n < forw->prev->n; forw = forw->prev)
	{
	tmp = forw->prev;
	swap_nodes(list, tmp, forw);
	print_list(*list);
	forw = forw->next;
	}
	}
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @node1: first node to be swapped
 * @node2: second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
	prev->next = node2;
	else
	*list = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;

	if (next)
	next->prev = node1;
}
