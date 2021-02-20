#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Matrix A:\n");
    Matrix *a = new_matrix(3, 4);
    random_fill(a);
    matrix_print(a);
    printf("Matrix B:\n");
    Matrix *b = new_matrix(4, 3);
    random_fill(b);
    matrix_print(b);
    printf("Matrix C (mult):\n");
    Matrix *c = mult_naive(a, b);
    matrix_print(c);
    free_matrix(a);
    free_matrix(b);
    free_matrix(c);
}
