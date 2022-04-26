#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#include "matrix_operations.h"



int main() {
    
    Matrix matrix;

    int size = 10000;

    alloc_matrix(&matrix,size,size);

    int N = matrix.N;
 
    srand(time(NULL));

    randomfill_matrix(&matrix);
    double seged;
    double solutions[N];

    #pragma omp parallel for private(seged) public(solutions) default(none)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                seged += abs(matrix.data[i][j]);
            }
            solutions[i] = seged;
        }
        
    printf("The matrixes infinity norm is: %lf\n",max(solutions,N));
    
    return 0;
}

