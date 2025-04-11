#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: The number of elements in the array
 *
 * Description: Prints the array after each swap of two elements.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;

	int temp;

	int swapped = 1;

	if (array == NULL || size < 2)
		return;

	while (swapped == 1)
	{
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
