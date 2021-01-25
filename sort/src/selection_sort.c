#include "sort.h"

void selection_sort(int *vec, int size) {
    for (int i = 0; i < size; i++) {
        int min_index = 0;
        for (int j = 0; j < size; j++) {
            if (vec[j] < vec[min_index]) {
                min_index = j;
            }
        }
        int temp = vec[i];
        vec[i] = vec[min_index];
        vec[min_index] = temp;
    }
}
