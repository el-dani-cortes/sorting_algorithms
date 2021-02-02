#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 *
 * @array: array with numbers to sort
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, j;
	int value;

	/*Calculate the gap*/
	while (h < size)
		h = h * 3 + 1;
	h = (h - 1) / 3;
	while (h > 0)
	{
		for (j = h; j < size; j++)
		{
			value = array[j];
			i = j;
			while (i > h - 1 && array[i - h] >= value)
			{
				array[i] = array[i - h];
				i = i - h;
			}
			array[i] =  value;
		}
		print_array(array, size);
		h = h / 3;
	}
}
