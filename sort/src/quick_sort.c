#include "sort.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int prepare_partition(int *vec, int f, int l) {
    int pivot = vec[f];
    int part = f;
    for (int i = f + 1; i <= l; i++) {
        if (vec[i] <= pivot) {
            part++;
            swap(&vec[i], &vec[part]);
        }
    }
    swap(&vec[f], &vec[part]);
    return part;
}

void _quick_sort(int *vec, int first, int last) {
    if (first < last) {
        int part = prepare_partition(vec, first, last);
        _quick_sort(vec, first, part - 1);
        _quick_sort(vec, part + 1, last);
    }
}

void quick_sort(int *vec, int size) {
    _quick_sort(vec, 0, size - 1);
}
