#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

//Struct that contains the data of the matrix
typedef struct Matrix {
	int N;
    int M;
    double **data;
} Matrix;

//Function to allocate matrix
void alloc_matrix(Matrix *matrix,int N,int M);
//Function for freeing the memory allocated by the matrix
void free_matrix(Matrix *matrix);
//Function to fill up the matrix with random numbers
void randomfill_matrix(Matrix *matrix);
//Function to print out the matrix
void print_matrix(const Matrix *matrix);
//Function to get maximum element of a matrix
double max(double *B,int N);
//Function to allocate dynamic array
void alloc_dynamic_array(double *array,int N);
#endif 