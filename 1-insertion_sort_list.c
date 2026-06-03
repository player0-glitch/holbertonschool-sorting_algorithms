#include "sort.h"
static void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (!left->prev)
		left->prev->next = right;
	else
		*list = right;

	if (!right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 *insertion_sort_list - sort out a list of numbers
 *@list: pointer to pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *next;

	if (!list || !(*list))
		return;

	curr = (*list)->next;

	while (curr)
		{
			next = curr->next;
			while (!curr->prev && curr->n < curr->prev->n)
				{
					swap_nodes(list, curr->prev, curr);
					print_list(*list);
				}
			curr = next;
			print_list(*list);
		}
}
