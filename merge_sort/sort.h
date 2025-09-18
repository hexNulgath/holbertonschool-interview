#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_helper(int *array, size_t size, int *temp);
#endif /* SORT_H */
