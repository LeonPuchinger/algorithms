#include "sort.h"
#include <stdlib.h>
#include <string.h>

void map_sort(int *vec, int size, int c) {
    int bin_size = size * c;
    int *bin = calloc(bin_size, sizeof(int));
    memset(bin, -1, bin_size * sizeof(int));
    int min = 0, max = 0;
    for (int i = 0; i < size; i++) {
        if (vec[i] < min) min = vec[i];
        if (vec[i] > max) max = vec[i];
    }
    double dist = (double)(max - min) / (double)(bin_size - 1);
    for (int i = 0; i < size; i++) {
        int pos = ((double)(vec[i] - min) / dist);
        int left = 0;
        if (bin[pos] != -1 && vec[i] <= bin[pos]) {
            left = 1;
        }
        while (bin[pos] != -1) {
            if (left) pos--;
            else pos++;
        }
        bin[pos] = vec[i];
    }
    int j = 0;
    for (int i = 0; i < bin_size; i++) {
        if (bin[i] != -1) {
            vec[j] = bin[i];
            j++;
        }
    }
    free(bin);
}
