#include <stdio.h>
#include "sort.h"
/**
 * swap - Swaps two elements in an array
 * @arr: The array in which elements will be swapped
 * @i: The index of the first element
 * @j: The index of the second element
 *
 * Return: Nothing (void)
 */
void swap(int *arr, int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The number of elements in the array
 *
 * Description: Prints the array after each swap.
 * Return: Nothing (void)
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, small;

	if (array == NULL || size < 2)
		return;

	for (; i < size - 1; i++)
	{
		small = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
			{
				small = j;
			}
		}
		if (small != i)
		{
			swap(array, i, small);
			print_array(array, size);
		}
	}
}
