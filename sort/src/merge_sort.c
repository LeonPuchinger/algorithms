#include "sort.h"
#include <stdlib.h>

void merge(int *vec, int f, int l, int m) {
    int size = l - f + 1;
    int f1 = f, l1 = m - 1;
    int f2 = m, l2 = l;
    int *new = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        if (f1 <= l1) {
            if (f2 <= l2) {
                if (vec[f1] <= vec[f2]) {
                    new[i] = vec[f1];
                    f1++;
                } else {
                    new[i] = vec[f2];
                    f2++;
                }
            } else {
                new[i] = vec[f1];
                f1++;
            }
        } else {
            new[i] = vec[f2];
            f2++;
        }
    }

    for (int i = 0; i < size; i++) {
        vec[f + i] = new[i];
    }
    free(new);
}

void _merge_sort(int *vec, int f, int l) {
    if (f < l) {
        int m = (f + l + 1) / 2;
        _merge_sort(vec, f, m - 1);
        _merge_sort(vec, m, l);
        merge(vec, f, l, m);
    }
}

void merge_sort(int *vec, int size) {
    _merge_sort(vec, 0, size - 1);
}
