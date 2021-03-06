#ifndef SORTING_H
#define SORTING_H

//simple sorting algorithms
void insertion_sort(int *vec, int size);
void bubble_sort(int *vec, int size);
void selection_sort(int *vec, int size);

//advanced sorting algorithms
void quick_sort(int *vec, int size);
void merge_sort(int *vec, int size);
void heap_sort(int *vec, int size);

//specialized sorting algorithms
void count_sort(int *vec, int size, int range_from, int range_to);
void map_sort(int *vec, int size, int c);

#endif
