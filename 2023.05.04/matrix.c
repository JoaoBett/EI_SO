#include <stdio.h>
#include <stdlib.h>
#include <debug.h>
#include "matrix.h"
#include <memory.h>


int** matrix_new(int num_rows, int num_cols){
    int** matrix = MALLOC(num_rows * sizeof(int*));
    int* data = MALLOC(num_rows * num_cols * sizeof(int));

    if(matrix != NULL && data !=NULL){
        for (int row = 0; row < num_rows; row++)
        {
            matrix[row]= &(data[row * num_cols]);
        }
    }
    else{
        return NULL;
    }

    return matrix;
}


void matrix_delete(int** matrix){
    if(matrix == NULL){
        printf("Já está a NULL não vamos fazer free.\n");
        return;
    }
    FREE(matrix[0]); //free dos dadow/buffer
    FREE(matrix);   //free do vetor aux da matrix
    matrix = NULL;
}

void matrix_fill(int **matrix, int num_rows, int num_cols, int target){
    int i, j;

    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < num_cols; j++)
        {
            matrix[i][j]= target;
        }   
    }
/*      Poderia ser uma boa abordagem, neste caso iremos usar a de cima

    int* aux_dados = matrix[0];
    int total = num_cols * num_rows;

    for (i = 0; i < total; i++)
    {
        aux_dados[i] = target;
    }
    
*/
}



void matrix_print(int **matrix, int num_rows, int num_cols){
    int i, j;

    for (i = 0; i < num_rows; i++)
    {
        for (j = 0; j < num_cols; j++)
        {
            printf("%d\t",matrix[i][j]);
        }   
        printf("\n");
    }
    
}

void matrix_mul(int** m1, int** m2, int m1r, int m1c, int m2r, int m2c){
    if (m1c != m2r)
    {   
        return NULL;
    }

    int i, j, k;
    int sum;

    int **matrix_result = matrix_new(m1r, m2c);
    
    for(i = 0;i < ; i++){
        for (j = 0; j < ; j++)
        {
            int sum = 0;
            for (k = 0; k < ; k++)
            {
            sum += m1[i][k] * m2[i][k];
            }
        }
        matrix_result[i][j]= sum;
    }

    
}