#include "sort.h"

/**
 * insertion_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void insertion_sort(int *array, size_t size)
{
	size_t i;
	int key, j;

	if (!array || size < 2)
		return;

	for (i = 1; i < size; i++)
		{
			key = array[i];
			j = i - 1;

			/* Move elements of array[0..i-1] that are greater than
			 * key */
			/* to one position ahead of their current position */
			while (j >= 0 && array[j] > key)
				{
					array[j + 1] = array[j];
					j--;
					print_array(array, size);
				}
			array[j + 1] = key;
		}
}
