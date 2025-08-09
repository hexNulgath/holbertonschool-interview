
#include <stdio.h>
#include <stddef.h>

/**
 * print_array - Prints the elements of an array
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 */
void print_array(int *array, size_t start, size_t end)
{
    size_t i;

    printf("Searching in array: ");
    for (i = start; i <= end; i++)
    {
        printf("%d", array[i]);
        if (i < end)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursive binary search to find first occurrence
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 * @value: Value to search for
 * Return: Index where value is located, or -1
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
    size_t mid;

    /* Kernel compliance: avoid C99 variable declarations in for/if */
    mid = start + (end - start) / 2;

    if (start > end)
        return (-1);

    print_array(array, start, end);

    if (array[mid] == value)
    {
        if (mid == start || array[mid - 1] != value)
            return ((int)mid);
        else
            return (advanced_binary_recursive(array, start, mid, value));
    }
    else if (array[mid] < value)
    {
        return (advanced_binary_recursive(array, mid + 1, end, value));
    }
    else
    {
        return (advanced_binary_recursive(array, start, mid, value));
    }
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 * Return: Index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);
    return (advanced_binary_recursive(array, 0, size - 1, value));
}
