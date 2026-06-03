#include "sort.h"
#include <stddef.h>

/**
 * swap_ints -  swapping numbers
 * @a: number to swap with b
 * @b: number to swap with a
 */
void swap_ints(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * lomuto_parition - algorithm for quick sort
 * @array: pointer to the array
 * @size: size of the array
 * @low: lower boundary
 * @high: higher boundary
 *
 * Return:lomuto_parition result
 */
static int lomuto_parition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
		{
			if (array[j] < pivot)
				{
					if (i != j)
						{
							swap_ints(&array[i],
								  &array[j]);
							print_array(array,
								    size);
						}
					i++;
				}
		}

	if (i != high)
		{
			swap_ints(&array[i], &array[high]);
			print_array(array, size);
		}
	return (i);
}

/**
 * quick_sort_recur - quick sort recursively
 *
 */
static void quick_sort_recur(int *array, size_t size, int low, int high)
{
	int pivot_idx;

	if (low < high)
		{
			pivot_idx = lomuto_parition(array, size, low, high);

			quick_sort_recur(array, size, low, pivot_idx - 1);

			quick_sort_recur(array, size, pivot_idx + 1, high);
		}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recur(array, size, 0, (int)size - 1);
}
