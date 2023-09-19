#include "sort.h"

/**
 * swap - swpa two elements of the lis and print the list
 *
 * @head: list to sort
 * @node1: node to swap
 * @node2: node to swap
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp_prev, *temp_next;

	if (node1 == NULL || node2 == NULL || *head == NULL)
		return;

	temp_prev = node1->prev;
	temp_next = node2->next;

	if (temp_prev != NULL)
		temp_prev->next = node2;
	if (temp_next != NULL)
		temp_next->prev = node1;

	node1->next = temp_next;
	node1->prev = node2;

	node2->next = node1;
	node2->prev = temp_prev;

	if (*head == node1)
		*head = node2;
	else if (*head == node2)
		*head = node1;
	print_list(*head);
}
/**
 * cocktail_sort_list - sort list using cocktail algo
 *
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = NULL, *right = NULL, *current = *list;
	int swaps;

	if (*list == NULL)
		return;

	do {
		swaps = 0;
		while (current->next != right)
		{
			if (current->n > current->next->n)
			{
				swap(list, current, current->next);
				swaps++;
			}
			else
				current = current->next;
		}
		right = current;
		while (current->prev != left)
		{
			if (current->n < current->prev->n)
			{
				swap(list, current->prev, current);
				swaps++;
			}
			else
				current = current->prev;
		}
		left = current;
	} while (swaps != 0);

}
