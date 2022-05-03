#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void gauss_jordan_solver(Matrix *matrix){
    int N = matrix->N;

    double *X = (double *)malloc(matrix->N*sizeof(double));
    for (int k = 0; k <= N-1; k++)
    {
        for (int i = 0; i <= N-1; i++)
        {
            if (k != i)
            {
                for (int j = k +1 ; j <= N; j++)
                {
                    matrix->data[i][j] = matrix->data[i][j] - (matrix->data[i][k] / matrix->data[k][k]) * matrix->data[k][j];
                }
                
            }
            
        }
        
    }
    for (int i = 0; i <= N-1; i++)
    {
        X[i] = matrix->data[i][N] / matrix->data[i][i];
    }

    for (int j = 0; j <= N-1; j++)
    {
       //printf( "\nTHE VALUE OF x%d IS %lf\n",j + 1,X[j]);
    }
}
int main(){

    Matrix matrix;

    alloc_matrix(&matrix,1000,1001);

    int N = matrix.N;

    double X[N];

    srand(time(NULL));

    randomfill_matrix(&matrix);
    
    //print_matrix(&matrix);
    clock_t start,end;
    double time_taken;

    start = clock();

    gauss_jordan_solver(&matrix);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf",N,time_taken);
    

    free_matrix(&matrix);

    return 0;
}
