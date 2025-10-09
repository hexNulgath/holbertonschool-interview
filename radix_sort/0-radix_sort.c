#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;
	size_t i;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int count[10] = {0};

		for (i = 0; i < size; i++)
		{
			count[(array[i] / exp) % 10]++;
		}

		for (i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}

		for (i = size; i > 0; i--)
		{
			output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
			count[(array[i - 1] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
		{
			array[i] = output[i];
		}
		print_array(array, size);
	}

	free(output);
}
