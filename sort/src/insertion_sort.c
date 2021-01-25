#include "sort.h"

void insertion_sort(int *vec, int size) {
    for (int s = 1; s < size; s++) {
        int p = s;
        while (p > 0 && vec[p] < vec[p - 1]) {
            int temp = vec[p];
            vec[p] = vec[p - 1];
            vec[p - 1] = temp;
            p--;
        }
    }
}
