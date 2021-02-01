#include "sort.h"

/**
 * _swap - Function to swap nodes
 *
 * @list: pointer to the head of the list
 * @cmp: pointer to the node that compares
 * @tmp: pointer to the node to swap
 *
 */
void _swap(listint_t **list, listint_t *cmp, listint_t *tmp)
{
	while (tmp && cmp->n > tmp->n)
	{
		if (tmp->next == NULL)
			cmp->next = NULL;
		else
		{
			cmp->next = tmp->next;
			tmp->next->prev = cmp;
		}
		cmp = cmp->prev;
		if (cmp == NULL)
		{
			cmp = *list;
			tmp->next = cmp;
			cmp->prev = tmp;
			tmp->prev = NULL;
			*list = tmp;
			tmp = cmp->next;
		}
		else
		{
			tmp->prev = cmp;
			tmp->next = cmp->next;
			cmp->next = tmp;
			tmp->next->prev = tmp;
		}
		print_list(*list);
	}
}

/**
 * insertion_sort_list - Insertion sort algorithm
 *
 * @list: linked list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cmp = NULL, *tmp = NULL, *mark = NULL;

	if (*list != NULL)
	{
		cmp = *list;
		tmp = cmp->next;
		while (tmp != NULL)
		{
			if (cmp->n > tmp->n)
			{
				mark = cmp;
				_swap(list, cmp, tmp); /*swap nodes*/
				cmp = mark->prev;
				tmp = mark;
			}
			/*Return nodes*/
			tmp = tmp->next;
			cmp = cmp->next;
		}
	}
}
