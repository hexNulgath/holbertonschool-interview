#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void heap_sort(int *array, size_t size) {
    if (array == NULL || size < 2)
        return;

    // Build the max heap
    heapify(array, size);
    print_array(array, size); // Print initial heap

    // Extract elements one by one
    for (size_t i = size - 1; i > 0; i--) {
        // Swap root with last element
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        // Sift down the new root (without printing inside)
        siftDown(array, i, 0);

        // Print after each root extraction
        print_array(array, size);
    }
}

void heapify(int *array, size_t count) {
    for (ssize_t i = (count / 2) - 1; i >= 0; i--) {
        siftDown(array, count, i);
    }
}

void siftDown(int *array, size_t count, size_t root) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < count && array[left] > array[largest])
        largest = left;

    if (right < count && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        int temp = array[root];
        array[root] = array[largest];
        array[largest] = temp;

        siftDown(array, count, largest);
    }
}