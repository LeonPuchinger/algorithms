#include "sort.h"

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int left_next(int i) {
    return 2 * i + 1;
}

int right_next(int i) {
    return 2 * i + 2;
}

int pred(int i) {
    return (i - 1) / 2;
}

void heapify(int *heap, int f, int l, int root) {
    int max = root;
    int left = left_next(root);
    if (left <= l && heap[left] > heap[max]) {
        max = left;
    }
    int right = right_next(root);
    if (right <= l && heap[right] > heap[max]) {
        max = right;
    }
    if (max != root) {
        swap(&heap[max], &heap[root]);
        heapify(heap, f, l, max);
    }
}

void build_heap(int *vec, int f, int l) {
    for (int i = pred(l); i >= f; i--) {
        heapify(vec, f, l, i);
    }
}

void _heap_sort(int *vec, int f, int l) {
    build_heap(vec, f, l);
    for (int i = l; i > f; i--) {
        swap(&vec[f], &vec[i]);
        heapify(vec, f, i - 1, f);
    }
}

void heap_sort(int *vec, int size) {
    _heap_sort(vec, 0, size - 1);
}
