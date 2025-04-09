#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *order
 * using the insertion sort algorithm.
 *
 * @list: A pointer to the pointer to the head of the list.
 *
 * This function sorts a doubly linked list using the insertion sort algorithm.
 * It repeatedly compares each node with its predecessor and swaps them if
 * they are in the wrong order. The sorting continues until the entire list is
 * sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current;
		temp = current->next;

		while (insertion_point->prev != NULL &&
			   insertion_point->n < insertion_point->prev->n)
		{
			if (insertion_point->next != NULL)
			{
				insertion_point->next->prev = insertion_point->prev;
			}

			insertion_point->prev->next = insertion_point->next;
			insertion_point->next = insertion_point->prev;
			insertion_point->prev = insertion_point->prev->prev;

			if (insertion_point->prev != NULL)
			{
				insertion_point->prev->next = insertion_point;
			}
			else
			{
				*list = insertion_point;
			}

			insertion_point->next->prev = insertion_point;

			print_list(*list);
		}

		current = temp;
	}
}
