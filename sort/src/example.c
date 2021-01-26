#include "sort.h"
#include <stdio.h>

void print_vec(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main() {
    printf("insertion sort:\n");
    int vec_a[5] = {8, 7, 2, 11, 18};
    insertion_sort(vec_a, 5);
    print_vec(vec_a, 5);
    printf("bubble sort:\n");
    int vec_b[5] = {8, 7, 2, 11, 18};
    bubble_sort(vec_b, 5);
    print_vec(vec_b, 5);
    printf("selection sort:\n");
    int vec_c[5] = {8, 7, 2, 11, 18};
    bubble_sort(vec_c, 5);
    print_vec(vec_c, 5);

    printf("quick sort:\n");
    int vec_d[5] = {8, 7, 2, 11, 18};
    quick_sort(vec_d, 5);
    print_vec(vec_d, 5);
    printf("merge sort:\n");
    int vec_e[5] = {8, 7, 2, 11, 18};
    merge_sort(vec_e, 5);
    print_vec(vec_e, 5);
    printf("heap sort:\n");
    int vec_f[5] = {8, 7, 2, 11, 18};
    heap_sort(vec_f, 5);
    print_vec(vec_f, 5);

    printf("count sort:\n");
    int vec_g[5] = {8, 7, 2, 11, 18};
    count_sort(vec_g, 5, 2, 18);
    print_vec(vec_g, 5);
}
