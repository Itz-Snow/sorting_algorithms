#include "sort.h"

/**
 * bubble_sort - this is the bubble sort algorithm, sorting array elements
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: Nothing
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int holder;
	int swapcheck; /* Flag to check if any swaps occurred in a pass */

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapcheck = 0; /* Reset the flag at the beginning of each pass */

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Swap elements */
				holder = array[j];
				array[j] = array[j + 1];
				array[j + 1] = holder;
				print_array(array, size);
				swapcheck = 1; /* Set the flag since a swap occurred */
			}
		}

		/* If no swaps occur, the array is already sorted. Break the loop. */
		if (swapcheck == 0)
			break;
	}
}
