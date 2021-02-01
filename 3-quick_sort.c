#include "sort.h"
#include <unistd.h>

/**
 * partition - Partition function to divide the array by th pivot
 *
 * @array: The array to be sorted
 * @lo: low position of the array
 * @hi: High posiiton of the array
 *
 * Return: Position of the pivot after divide array
 *
 */
unsigned long int partition(int *array, unsigned long int lo,
			    unsigned long int hi)
{
	int pivot, tmp;
	unsigned long int i, j;

	pivot = array[hi];
	i = lo;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			/*swap values*/
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
		}
	}
	/*swap pivot to the i position*/
	tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;
	return (i);
}

/**
 * _qsort - quick sort algorithm
 *
 * @array: The array to be sorted
 * @lo: low position of the array
 * @hi: High posiiton of the array
 *
 */
void _qsort(int *array, unsigned long int lo, unsigned long int hi)
{
	unsigned long int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi);
		print_array(array, 3);
		_qsort(array, p + 1, hi);
		if (p > 0)
			_qsort(array, lo, p - 1);
	}
}

/**
 * quick_sort - quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1);
}
