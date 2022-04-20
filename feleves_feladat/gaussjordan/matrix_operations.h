#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <float.h>

//Struct that contains the data of the matrix
typedef struct Matrix {
	int N;
    int M;
    double **data;
} Matrix;

//Function to allocate matrix
void alloc_matrix(Matrix *matrix,int N,int M){
	matrix->N = N;
	matrix->M = M;
	matrix->data = (double **)malloc(matrix->N*sizeof(double));
    for (int i = 0; i < matrix->M; i++)
    {
        matrix->data[i] = (double *)malloc(matrix->M*sizeof(double));
    }
}
//Function for freeing the memory allocated by the matrix
void free_matrix(Matrix *matrix){
	for (int i = 0; i < matrix->M; i++)
    {
        free(matrix->data[i]);
    }  
    free(matrix->data);
}
//Function to fill up the matrix with random numbers
void randomfill_matrix(Matrix *matrix){
    for (int i = 0; i < matrix->N; i++)
    {        
        for (int k = 0; k < matrix->M; k++)
        {
            matrix->data[i][k] = rand() % 100;           
        }   
    }
}
//Function to print out the matrix
void print_matrix(const Matrix *matrix){
    for (int i = 0; i < matrix->N; i++)
    {        
        for (int k = 0; k < matrix->M; k++)
        {
            printf("%lf ",matrix->data[i][k]);
        }
        printf("\n");        
    }
}
//Function to get maximum element of a matrix
double max(double *B,int N){
    double max = DBL_MIN;
    for (int i = 0; i < N; i++)
    {
        //printf("%d ",B[i]);
        if(B[i] > max){
            max = B[i];
        }
    }
    return max;  
}

#endif 