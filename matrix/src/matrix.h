#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int i, j, **matrix;
} Matrix;

Matrix *new_matrix(int i, int j);

void free_matrix(Matrix *matrix);

void random_fill(Matrix *matrix);

void matrix_print(Matrix *matrix);

Matrix *mult_naive(Matrix *a, Matrix *b);

Matrix *mult_strassen(Matrix *a, Matrix *b);

#endif
