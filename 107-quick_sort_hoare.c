#include "sort.h"

/**
* partition - hoare partiton scheme
* @array: array to sort
* @size: array size
* @low: first position subarray
* @high: last position subarray
* Return: partition position
**/
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high - 1];
	size_t i = low;
	size_t j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (j);

		if (array[i] != array[j])
		{
			array[i] = array[i] + array[j];
			array[j] = array[i] - array[j];
			array[i] = array[i] - array[j];

			print_array(array, size);
		}
		i++;
		j--;
	}
}

/**
* qsorth - quick sort hoare
* @array: array to sort
* @size: array size
* @low: first position subarray
* @high: last position subarray
* Return: partition position
**/
void qsorth(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot;
	/* base condition */

	if (low < high)
	{
		/* rearrange the elements across pivot */
		pivot = partition(array, low, high, size);

		/* recursion left to pivot*/
		if (pivot)
			qsorth(array, low, pivot, size);

		/* recursion right to pivot */
		qsorth(array, pivot + 1, high, size);
	}
}

/**
* quick_sort_hoare - quick sort algorithm
* @array: array to sort
* @size: array size
**/
void quick_sort_hoare(int *array, size_t size)
{
	if (size == 0 || array == NULL)
		return;
	qsorth(array, 0, size - 1, size);
}
