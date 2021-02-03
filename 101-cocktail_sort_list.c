#include "sort.h"
/**
 * swap_forward - Swaps forward two nodes in linked list.
 *
 * @current: Pointer to the current node to swap.
 * @list: Popinter to the list of nodes.
 *
 *  Return: always 1.
 */
int swap_forward(listint_t *current, listint_t **list)
{
	listint_t *move = NULL;

	move = current->next;

	move->prev = current->prev;
	if (current->prev)
		current->prev->next = move;
	else
		*list = current->next;

	current->next = move->next;
	current->prev = move;
	move->next = current;
	if (current->next)
		current->next->prev = current;

	print_list(*list);
	return (1);
}
/**
 * swap_backward - Swaps backward two nodes in linked list.
 *
 * @current: Pointer to the current node to swap.
 * @list: Popinter to the list of nodes.
 *
 *  Return: Always 1.
 */
int swap_backward(listint_t *current, listint_t **list)
{
	listint_t *move = NULL;

	move = current->prev;

	move->next = current->next;
	current->next->prev = move;

	current->prev = move->prev;
	current->next = move;
	move->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	print_list(*list);
	return (1);
}
/**
 * cocktail_sort_list -Cocktail sort algorithm
 *
 *@list: Pointer to the head of the list.
 *
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int _switch = 1;

	if (list)
	{
		current = *list;
		while (_switch)
		{
			_switch = 0;
			while (current->next)
			{
				if (current->n > current->next->n)
				{
					_switch = swap_forward(current, list);
					continue;
				}
				current = current->next;
			}
			if (!_switch)
				break;
			_switch = 0;
			while (current->prev)
			{
				if (current->n < current->prev->n)
				{
					_switch = swap_backward(current, list);
					continue;
				}
				current = current->prev;
			}
		}
	}
}
