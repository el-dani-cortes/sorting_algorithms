#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/*Function that prints a arrray*/
void print_array(const int *array, size_t size);

/*Function that prints a list*/
void print_list(const listint_t *list);

/*Bubble sort algorithm*/
void bubble_sort(int *array, size_t size);

/*Insertion sort algorithm*/
void insertion_sort_list(listint_t **list);

/*Selection sort algorithm*/
void selection_sort(int *array, size_t size);

/*Quick sort - Lomuto partition scheme*/
void quick_sort(int *array, size_t size);

/*Shell sort algorithm*/
void shell_sort(int *array, size_t size);

/*Counting sort algorithm*/
void counting_sort(int *array, size_t size);

/*Counting sort algorithm*/
void cocktail_sort_list(listint_t **list);

/*Quick sort - Hoare Partition scheme */
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
