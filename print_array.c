#include "sort.h"
#include <stdio.h>

/*
 *print_array - prints array of ints
 *@array: pointer to the start of the array
 *@size: size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i = 0;
	while (array && i < size)
		{
			if (i > 0)
				printf(", ");
			printf("%d", array[i]);
			++i;
		}
	printf("\n");
}

/**
 *print_list- prints linked list of ints
 *@list: pointer to the head of the list
 */
void print_list(const listint_t *list)
{
	int i = 0;

	while (list)
		{
			if (i > 0)
				printf(", ");
			printf("%d", list->n);
			++i;
			list = list->next;
		}
	printf("\n");
}
