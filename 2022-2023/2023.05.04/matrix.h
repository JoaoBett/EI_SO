#ifndef _MATRIX_H_
#define _MATRIX_H_

int** matrix_new(int num_rows, int num_cols);

void matrix_delete(int ** matrix);

void matrix_fill(int **matrix, int num_rows, int num_cols, int target);

void matrix_print(int **matrix, int num_rows, int num_cols);

void matrix_mul(int** m1, int** m2, int m1r, int m1c, int m2r, int m2c);

#endif