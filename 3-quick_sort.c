#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @arr: The array containing elements to swap
 * @i: Index of the first element
 * @j: Index of the second element
 *
 * Description: This function swaps the elements at positions i and j
 * in the given array using a temporary variable.
 */
void swap(int *arr, int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

/**
 * lomuto - Implements the Lomuto partition scheme for Quick Sort
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the entire array for printing purposes
 *
 * Description: This function takes the last element as pivot,
 * places the pivot element at its correct position in sorted
 * array, and places all smaller elements to the left and all
 * greater elements to the right of the pivot.
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs_recursive - Recursive function for Quick Sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the entire array for printing purposes
 *
 * Description: This function recursively implements the Quick Sort
 * algorithm using the Lomuto partition scheme to sort an array
 * of integers in ascending order.
 */
void qs_recursive(int *array, int low, int high, size_t size)
{
	int index_p;

	if (low < high)
	{
		index_p = lomuto(array, low, high, size);

		qs_recursive(array, low, index_p - 1, size);
		qs_recursive(array, index_p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: This function implements the Quick Sort algorithm
 * to sort an array of integers in ascending order. It uses the
 * Lomuto partition scheme and prints the array after each swap.
 * If the array is NULL or has less than 2 elements, it returns
 * without doing anything.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qs_recursive(array, 0, size - 1, size);
}
