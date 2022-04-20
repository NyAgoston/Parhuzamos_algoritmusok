#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

void gauss_jordan_solver(Matrix *matrix)
{
    int k, i, j;

    double l;

    int var = matrix->N;
 
    for ( k = 0;k < var;k++ )
    {
        for ( i = 0;i <= var;i++ )
        {
            l = matrix->data[ i ][ k ];
 
            for ( j = 0;j <= var;j++ )
            {
                if ( i != k ){
                    matrix->data[i][j] = (matrix->data[k][k]*matrix->data[i][j])-(l*matrix->data[k][j]);
                }
            }
            
        }
        
    }
    printf( "\nSolutions:" );
 
    for ( i = 0;i < matrix->N;i++ )
    {
        printf( "\nTHE VALUE OF x%d IS %lf\n", i + 1,matrix->data[i][var] /matrix->data[i][i]);
    }
 
}

int main(){

    Matrix matrix;

    alloc_matrix(&matrix,10,11);

    int N = matrix.N;

    srand(time(NULL));

    randomfill_matrix(&matrix);
    
    print_matrix(&matrix);

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
