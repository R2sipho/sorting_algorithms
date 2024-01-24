#include "sort.h"

/**
 * swap_elements - Swap two elements in an array.
 * @element1: The first element to swap.
 * @element2: The second element to swap.
 */
void swap_elements(int *element1, int *element2)
{
    int temporary;

    temporary = *element1;
    *element1 = *element2;
    *element2 = temporary;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                swap_elements(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_elements(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int partition_index;

    if (right - left > 0)
    {
        partition_index = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, partition_index - 1);
        lomuto_sort(array, size, partition_index + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

