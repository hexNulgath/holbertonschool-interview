#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Build the max heap */
	heapify(array, size);

	/* Extract elements one by one */
	for (size_t i = size - 1; i > 0; i--)
	{
		/* Swap root with last element */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		siftDown(array, i, 0, size);
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to heapify
 * @count: Number of elements in the array
 */
void heapify(int *array, size_t count)
{
	ssize_t i;

	for (i = (count / 2) - 1; i >= 0; i--)
	{
		siftDown(array, count, i, count);
	}
}

/**
 * siftDown - Maintains heap property by moving element down the heap
 * @array: The array representing the heap
 * @count: Size of the heap portion
 * @root: Index of the root of the subtree
 * @total_size: Total size of the array (for printing)
 */
void siftDown(int *array, size_t count, size_t root, size_t total_size)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < count && array[left] > array[largest])
		largest = left;

	if (right < count && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int temp = array[root];

		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, total_size);
		siftDown(array, count, largest, total_size);
	}
}