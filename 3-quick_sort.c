#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm (Lomuto partition)
* @array: The array to sort
* @size: Number of elements in the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* quick_sort_recursive - Recursive helper function for quick_sort
* @array: The array to sort
* @low: Start index of the sub-array
* @high: End index of the sub-array
* @size: Total size of the array (for printing)
*/

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* lomuto_partition - Applies Lomuto partition scheme to a sub-array
* @array: The array to partition
* @low: Starting index of the sub-array
* @high: Ending index (pivot)
* @size: Total size of the array (for printing)
*
* Return: Final position of the pivot
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;

	int i;

	int j;

	int temp;

	pivot = array[high];

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[i] != array[j])
			{
				if (array[i] != array[j])
				{
					temp = array[j];
					array[j] = array[i];
					array[i] = temp;
					print_array(array, size);
				}
			}
		}
	}

	if ((i + 1) != high && array[i + 1] != array[high])
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
