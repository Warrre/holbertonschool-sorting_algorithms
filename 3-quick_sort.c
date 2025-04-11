#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/**
 * partition - partitions the array
 * @arr: array to partition
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto_partition(int arr[], size_t low, size_t high, size_t size)
{
	int pivot = arr[high];
	size_t i = low - 1;
	size_t j;

	if (arr == NULL || size < 2)
	{
		return (-1);
	}

	if (high >= size || low > high)
	{
		return (-1);
	}

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&arr[i + 1], &arr[high]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * helper - helper function for quick_sort
 * @arr: array to sort
 * @low: low index
 * @high: high index
 * @size: size of the array
 */
void helper(int arr[], int low, int high, size_t size)
{
	if (arr == NULL || size < 2)
	{
		return;
	}

	if (low < high)
	{
		int pi = partition(arr, low, high, size);

		helper(arr, low, pi - 1, size);
		helper(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
	{
		return;
	}

	helper(array, 0, size - 1, size);
}
