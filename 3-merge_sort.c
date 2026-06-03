#include "sort.h"
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays of array[]
 * @array: The source array containing sub-arrays
 * @temp: Temporary array buffer used for merging
 * @left: Starting index of left sub-array
 * @mid: Ending index of left sub-array
 * @right: Ending index of right sub-array
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left;    /* Initial index of first sub-array */
	size_t j = mid + 1; /* Initial index of second sub-array */
	size_t k = left;    /* Initial index of merged sub-array */

	while (i <= mid && j <= right)
		{
			if (array[i] <= array[j])
				temp[k++] = array[i++];
			else
				temp[k++] = array[j++];
		}

	/* Copy remaining elements of left sub-array, if any */
	while (i <= mid)
		temp[k++] = array[i++];

	/* Copy remaining elements of right sub-array, if any */
	while (j <= right)
		temp[k++] = array[j++];

	/* Copy the sorted elements back into the original array */
	for (i = left; i <= right; i++)
		array[i] = temp[i];
}

/**
 * merge_sort_recursion - Helper function that divides the array
 * @array: The array to sort
 * @temp: Temporary array buffer
 * @left: Left bound index
 * @right: Right bound index
 */
void merge_sort_recursion(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left < right)
		{
			mid = left + (right - left) / 2;

			/* Sort first and second halves */
			merge_sort_recursion(array, temp, left, mid);
			merge_sort_recursion(array, temp, mid + 1, right);

			/* Merge the sorted halves */
			merge(array, temp, left, mid, right);
		}
}

/**
 * merge_sort - Top-level Merge Sort implementation
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	/* Allocate the temporary array buffer just once */
	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursion(array, temp, 0, size - 1);

	free(temp);
}
