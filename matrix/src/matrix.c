#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *new_matrix(int i, int j) {
    Matrix *new = malloc(sizeof(Matrix));
    new->i = i;
    new->j = j;
    new->matrix = calloc(i, sizeof(int *));
    for (int n = 0; n < i; n++) {
        new->matrix[n] = calloc(j, sizeof(int));
    }
    return new;
}

void free_matrix(Matrix *matrix) {
    for (int n = 0; n < matrix->i; n++) {
        free(matrix->matrix[n]);
    }
    free(matrix->matrix);
    free(matrix);
}

void random_fill(Matrix *matrix) {
    for (int i = 0; i < matrix->i; i++) {
        for (int j = 0; j < matrix->j; j++) {
            matrix->matrix[i][j] = rand() % 10;
        }
    }
}

void matrix_print(Matrix *matrix) {
    for (int i = 0; i < matrix->i; i++) {
        printf("[");
        for (int j = 0; j < matrix->j; j++) {
            printf(" %d", matrix->matrix[i][j]);
        }
        printf(" ]\n");
    }
}

Matrix *mult_naive(Matrix *a, Matrix *b) {
    if (a->j != b->i) {
        return NULL;
    }
    Matrix *new = new_matrix(a->i, b->j);
    for (int i = 0; i < new->i; i++) {
        for (int j = 0; j < new->j; j++) {
            for (int n = 0; n < a->j; n++) {
                new->matrix[i][j] += a->matrix[i][n] * b->matrix[n][j];
            }  
        }
    }
    return new;
}
