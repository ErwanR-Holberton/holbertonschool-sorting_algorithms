#include "deck.h"
/**
 * card_value - calculate the value of a card
 * @card: pointer to the card
 * Return: value of the card or 0
*/
int card_value(const card_t *card)
{
	int value = 0;

	if (card->value == NULL)
		return (0);

	if (strlen(card->value) == 1)
		value = card->value[0] - 48;
	else
	{
		if (strcmp(card->value, "10") == 0)
			value = 10;
		if (strcmp(card->value, "Ace") == 0)
			value = 1;
		if (strcmp(card->value, "Jack") == 0)
			value = 11;
		if (strcmp(card->value, "Queen") == 0)
			value = 12;
		if (strcmp(card->value, "King") == 0)
			value = 13;
	}
	return (card->kind * 13 + value);
}
/**
 * insertion_recursion - second part of insertion
 * @list: the list to sort
 * @ptr: pointer to the current node to sort
*/
void insertion_recursion(deck_node_t *ptr, deck_node_t **list)
{
	deck_node_t *prev_prev, *previous, *the_next;

	if (ptr->prev == NULL)
		return;
	if (card_value(ptr->card) < card_value(ptr->prev->card))
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
		insertion_recursion(ptr, list);
	}
}
/**
 * sort_deck - sort a deck (using insertion sort list algo)
 * @deck: the list to sort
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *ptr;

	if (*deck == NULL)
		return;
	ptr = (*deck)->next;

	while (ptr != NULL)
	{
		insertion_recursion(ptr, deck);
		ptr = ptr->next;
	}
}


