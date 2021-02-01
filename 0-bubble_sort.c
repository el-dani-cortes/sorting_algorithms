#include "sort.h"

/**
 * bubble_sort - Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int j, _switch = 1;
	int tmp = 1;

	while (_switch)
	{
		_switch = 0;
		for (j = 1; j < size; j++)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
				_switch = 1;
			}
		}

	}
}
