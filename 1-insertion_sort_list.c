#include "sort.h"

/**
 * swap_nodes - Swaps nodes in a doubly linked list
 * @h: A pointer to the head of a doubly linked list
 * @n1: pointer to first node to swap
 * @n2: the second node to swap
 */

void node_swap(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;

	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;

}

/**
 * insertion_sort_list - sort a doubly linked list of ints using insertion sort algorithm
 * @list: A pointer to head of a doubly linked list
 *
 * Description: print the list after swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insertion = current->prev;
		while (insertion != NULL && current->n < insertion->n)
		{
			node_swap(list, &insertion, current);
			print_list((const listint_t *)*list);
		}
	}
}


