#include "sort.h"
#include <unistd.h>

/**
 * partition - Partition function to divide the array by th pivot
 *
 * @array: The array to be sorted
 * @lo: low position of the array
 * @hi: High posiiton of the array
 * @size: Size of the array
 *
 * Return: Position of the pivot after divide array
 *
 */
unsigned long int partition(int *array, unsigned long int lo,
			    unsigned long int hi, unsigned long int size)
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
			if (array[j] != array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	/*swap pivot to the i position*/
	if (array[i] != array[hi])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * _qsort - quick sort algorithm
 *
 * @array: The array to be sorted
 * @lo: low position of the array
 * @hi: High posiiton of the array
 * @size: Size of the array
 *
 */
void _qsort(int *array, unsigned long int lo, unsigned long int hi,
	    unsigned long int size)
{
	unsigned long int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		if (p > 0)
			_qsort(array, lo, p - 1, size);
		_qsort(array, p + 1, hi, size);
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
	if (size == 0)
		return;
	_qsort(array, 0, size - 1, size);
}
