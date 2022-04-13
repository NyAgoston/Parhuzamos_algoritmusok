#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matrix {
	int N;
    int M;
    double **data;
} Matrix;

void alloc_matrix(Matrix *matrix,int N,int M){
	matrix->N = N;
	matrix->M = M;
	matrix->data = (double **)malloc(matrix->N*sizeof(double));
    for (int i = 0; i < matrix->M; i++)
    {
        matrix->data[i] = (double *)malloc(matrix->M*sizeof(double));
    }

}
void free_matrix(Matrix *matrix){
	for (int i = 0; i < matrix->M; i++)
    {
        free(matrix->data[i]);
    }
    
    free(matrix->data);

}
void randomfill_matrix(Matrix *matrix){
    for (int i = 0; i < matrix->N; i++)
    {        
        for (int k = 0; k < matrix->M; k++)
        {
            matrix->data[i][k] = rand() % 100;           
        }   
    }
}
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

int main(){

	Matrix matrix;

	alloc_matrix(&matrix,2,2);
 	
	srand(time(NULL));

	randomfill_matrix(&matrix);
    
	print_matrix(&matrix);

	free_matrix(&matrix);

	return 0;
}