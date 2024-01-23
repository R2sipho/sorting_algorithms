#include "sort.h"

/**
 * swap_integers - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min_ptr;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_ptr = array + i;
		for (j = i + 1; j < size; j++)
			min_ptr = (array[j] < *min_ptr) ? (array + j) : min_ptr;

		if ((array + i) != min_ptr)
		{
			swap_integers(array + i, min_ptr);
			print_array(array, size);
		}
	}
}

