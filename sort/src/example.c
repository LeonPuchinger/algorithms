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
}
