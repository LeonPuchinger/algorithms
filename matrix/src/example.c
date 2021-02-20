#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Matrix A:\n");
    Matrix *a = new_matrix(4, 4);
    random_fill(a);
    matrix_print(a);
    printf("Matrix B:\n");
    Matrix *b = new_matrix(4, 4);
    random_fill(b);
    matrix_print(b);
    printf("Matrix C (mult-naive):\n");
    Matrix *c = mult_naive(a, b);
    matrix_print(c);
    free_matrix(c);
    printf("Matrix D (mult-strassen):\n");
    Matrix *d = mult_strassen(a, b);
    if (d == NULL) {
        printf("Strassen can only mult quadratic matrices\n");
    } else {        
        matrix_print(d);
        free_matrix(d);
    }
    free_matrix(a);
    free_matrix(b);
}
