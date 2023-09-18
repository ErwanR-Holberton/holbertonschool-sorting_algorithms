#include "sort.h"
/**
 * insertion_recursion - second part of insertion
 * @list: the list to sort
 * @ptr: pointer to the current node to sort
*/
void insertion_recursion(listint_t *ptr, listint_t **list)
{
	listint_t *prev_prev, *previous, *the_next;

	if (ptr->prev == NULL)
		return;
	if (ptr->n < ptr->prev->n)
	{
		prev_prev = ptr->prev->prev;
		previous = ptr->prev;
		the_next = ptr->next;

		if (ptr->prev == *list)
			*list = ptr;

		if (ptr->next != NULL)
			ptr->next->prev = ptr->prev;
		if (ptr->prev->prev != NULL)
			ptr->prev->prev->next = ptr;

		ptr->next = previous;
		ptr->prev = prev_prev;

		previous->next = the_next;
		previous->prev = ptr;

		print_list(*list);
		insertion_recursion(ptr, list);
	}
}
/**
 * insertion_sort_list - sort list using insertion algorithm
 * @list: the list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr;

	if (*list == NULL)
		return;
	ptr = (*list)->next;

	while (ptr != NULL)
	{
		insertion_recursion(ptr, list);
		ptr = ptr->next;
	}
}
