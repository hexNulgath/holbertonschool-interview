#include "sort.h"

void merge_sort_helper(int *array, size_t size, int *temp)
{
    if (size < 2)
        return;
    
    size_t mid = size / 2;
    size_t i = 0, j = mid, k = 0;

    // Sort left half
    merge_sort_helper(array, mid, temp);
    // Sort right half
    merge_sort_helper(array + mid, size - mid, temp);
    
    printf("Merging...\n");
    while (i < mid && j < size) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    
    printf("[left]: ");
    print_array(array, mid);
    printf("[right]: ");
    print_array(array + mid, size - mid);
    
    while (i < mid)
        temp[k++] = array[i++];
    while (j < size)
        temp[k++] = array[j++];

    for (i = 0; i < size; i++)
        array[i] = temp[i];
    
    printf("[Done]: ");
    print_array(array, size);
}

void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    
    int *temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;
    
    merge_sort_helper(array, size, temp);
    
    free(temp);
}