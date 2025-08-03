#ifndef SORT_H
#define SORT_H
void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void siftDown(int *array, size_t count, size_t root);
void heapify(int *array, size_t count);
#endif /* SORT_H */