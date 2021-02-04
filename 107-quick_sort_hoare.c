#include "sort.h"

/**
* partition - hoare partiton scheme
*
* @array: array to sort
* @size: array size
* @lo: first position subarray
* @hi: last position subarray
*
* Return: partition position
*
**/
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo;
	int j = hi;

	while (1)
	{

		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (i);
		array[i] = array[i] + array[j];
		array[j] = array[i] - array[j];
		array[i] = array[i] - array[j];
		print_array(array, size);
		i++;
		j--;
	}
}

/**
* qsort_hoare - quick sort by hoare scheme
*
* @array: array to sort
* @size: array size
* @lo: first position subarray
* @hi: last position subarray
*
* Return: partition position
*
**/
void qsort_hoare(int *array, int lo, int hi, size_t size)
{
	int position;

	/* base condition */
	if (lo < hi)
	{
		/* rearrange the elements across pivot */
		position = partition(array, lo, hi, size);

		/* recursion left to pivot*/
		qsort_hoare(array, lo, position - 1, size);

		/* recursion right to pivot */
		qsort_hoare(array, position, hi, size);
	}
}

/**
* quick_sort_hoare - quick sort algorithm
*
* @array: array to sort
* @size: array size
*
**/
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	qsort_hoare(array, 0, size - 1, size);
}
