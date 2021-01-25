#include "sort.h"

void bubble_sort(int *vec, int size) {
    for (int i = size; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}
