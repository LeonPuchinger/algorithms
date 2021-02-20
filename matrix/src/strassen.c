#include "matrix.h"
#include <stdlib.h>

Matrix *add(Matrix *matrix_a, Matrix *matrix_b) {
    Matrix *new = new_matrix(matrix_a->i, matrix_a->j);
    for (int i = 0; i < matrix_a->i; i++) {
        for (int j = 0; j < matrix_a->j; j++) {
            new->matrix[i][j] = matrix_a->matrix[i][j] + matrix_b->matrix[i][j];
        }
    }
    return new;
}

Matrix *sub(Matrix *matrix_a, Matrix *matrix_b) {
    Matrix *new = new_matrix(matrix_a->i, matrix_a->j);
    for (int i = 0; i < matrix_a->i; i++) {
        for (int j = 0; j < matrix_a->j; j++) {
            new->matrix[i][j] = matrix_a->matrix[i][j] - matrix_b->matrix[i][j];
        }
    }
    return new;
}

Matrix *light_copy_matrix(Matrix *matrix, int i0, int j0, int i1, int j1) {
    Matrix *m = calloc(1, sizeof(Matrix));
    m->i = i1-i0;
    m->j = j1-j0;
    m->matrix = calloc(m->i, sizeof(int *));
    for (int n = 0; n < m->i; n++) {
        m->matrix[n] = matrix->matrix[n+i0]+j0;
    }
    return m;
}

Matrix *fuse_quadratic_matrices(Matrix *m11, Matrix *m12, Matrix *m21, Matrix *m22, int size) {
    Matrix *new = new_matrix(size, size);
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < size; b++) {
            if (a < size/2) {
                if (b < size/2) {
                    new->matrix[a][b] = m11->matrix[a][b];
                } else {
                    new->matrix[a][b] = m12->matrix[a][b-size/2];
                }
            } else {
                if (b < size/2) {
                    new->matrix[a][b] = m21->matrix[a-size/2][b];
                } else {
                    new->matrix[a][b] = m22->matrix[a-size/2][b-size/2];
                }
            }
        }
    }
    return new;
}

Matrix *mult_strassen(Matrix *matrix_m, Matrix *matrix_n) {
    int size = matrix_m->i;
    if ((size != matrix_m->j) || (size != matrix_n->i) || (size != matrix_n->j)) {
        return NULL;
    }
    if (size == 1) {
        Matrix *new = new_matrix(1, 1);
        new->matrix[0][0] = matrix_m->matrix[0][0] * matrix_n->matrix[0][0];
        return new;
    }

    Matrix *m11 = light_copy_matrix(matrix_m, 0, 0, size/2, size/2);
    Matrix *m12 = light_copy_matrix(matrix_m, 0, size/2, size/2, size);
    Matrix *m21 = light_copy_matrix(matrix_m, size/2, 0, size, size/2);
    Matrix *m22 = light_copy_matrix(matrix_m, size/2, size/2, size, size);

    Matrix *n11 = light_copy_matrix(matrix_n, 0, 0, size/2, size/2);
    Matrix *n12 = light_copy_matrix(matrix_n, 0, size/2, size/2, size);
    Matrix *n21 = light_copy_matrix(matrix_n, size/2, 0, size, size/2);
    Matrix *n22 = light_copy_matrix(matrix_n, size/2, size/2, size, size);

    Matrix *t1, *t2;

    Matrix *h1 = mult_strassen(t1 = add(m11, m22), t2 = add(n11, n22));
    free_matrix(t1); free_matrix(t2);
    Matrix *h2 = mult_strassen(t1 = add(m21, m22), n11);
    free_matrix(t1);
    Matrix *h3 = mult_strassen(m11, t2 = sub(n12, n22));
    free_matrix(t2);
    Matrix *h4 = mult_strassen(m22, t2 = sub(n21, n11));
    free_matrix(t2);
    Matrix *h5 = mult_strassen(t1 = add(m11, m12), n22);
    free_matrix(t1);
    Matrix *h6 = mult_strassen(t1 = sub(m21, m11), t2 = add(n11, n12));
    free_matrix(t1); free_matrix(t2);
    Matrix *h7 = mult_strassen(t1 = sub(m12, m22), t2 = add(n21, n22));
    free_matrix(t1); free_matrix(t2);

    Matrix *o11 = add(t2 = sub(t1 = add(h1, h4), h5), h7);
    free_matrix(t1); free_matrix(t2);
    Matrix *o12 = add(h3, h5);
    Matrix *o21 = add(h2, h4);
    Matrix *o22 = add(t1 = sub(h1, h2), t2 = add(h3, h6));
    free_matrix(t1); free_matrix(t2);

    Matrix *new = fuse_quadratic_matrices(o11, o12, o21, o22, size);

    free(m11->matrix); free(m12->matrix); free(m21->matrix); free(m22->matrix);
    free(n11->matrix); free(n12->matrix); free(n21->matrix); free(n22->matrix);
    free(m11); free(m12); free(m21); free(m22);
    free(n11); free(n12); free(n21); free(n22);

    free_matrix(h1); free_matrix(h2);
    free_matrix(h3); free_matrix(h4);
    free_matrix(h5); free_matrix(h6);
    free_matrix(h7);
    
    free_matrix(o11); free_matrix(o12);
    free_matrix(o21); free_matrix(o22);

    return new;
}
