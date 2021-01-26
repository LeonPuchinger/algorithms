#include "sort.h"
#include <stdlib.h>

void count_sort(int *vec, int size, int range_from, int range_to) {
    int counter_size = range_to - range_from;
    if (counter_size < 0) counter_size = -counter_size;
    counter_size++;

    int *counter = calloc(counter_size, sizeof(int));
    for (int i = 0; i < size; i++) {
        counter[vec[i] - range_from] += 1;
    }
    int j = 0;
    for (int i = 0; i < counter_size; i++) {
        if (counter[i]) {
            vec[j] = i + range_from;
            j++;
        }
    }
    free(counter);
}
