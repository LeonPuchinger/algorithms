#include "sort.h"
#include <stdio.h>

void print_vec(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main() {
    int vec[5] = {8, 7, 2, 11, 18};
    insertion_sort(vec, 5);
    print_vec(vec, 5);
}
