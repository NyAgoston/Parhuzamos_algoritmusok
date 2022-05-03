#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"
#include "omp.h"

int main(){

    Matrix matrix;

    alloc_matrix(&matrix,10,11);

    int N = matrix.N;

    double X[N];


    srand(time(NULL));

    randomfill_matrix(&matrix);
    
    //print_matrix(&matrix);
    int k,i,j,row;
    #pragma omp paralell private(k,i,j,row) shared(matrix)
        double my_rank = omp_get_thread_num();
        double bsize = N/omp_get_num_threads();
        if (my_rank != 0)
        {
            for (k = my_rank * bsize; k <= (my_rank * bsize) + bsize; k++)
            {
                row = Get(my_rank);
                Put(my_rank + 1,row);
                for (i = 0; i <= k + bsize; i++)
                {
                    if(row != i){
                        for (j = 0; i <= N + 1; i++)
                        {
                            matrix.data[i][j] = (matrix.data[i][row]/matrix.data[row][row]) * matrix.data[row][j];
                        }
                        
                    }
                }
                
            }
            
        }else{
            for (k = (my_rank * bsize); k <= (my_rank * bsize) + bsize; k++)
            {
                Put(my_rank + 1,k);
                for (i = 0; i <= k + bsize; i++)
                {
                    if (k != i)
                    {
                        for (j = k + 1; j <= N + 1; j++)
                        {
                            matrix.data[i][j] -= (matrix.data[i][k]/matrix.data[k][k]) * matrix.data[k][j];
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
    
    
    
    /*
    for (int j = 0; j <= N-1; j++)
    {
       printf( "\nTHE VALUE OF x%d IS %lf\n",j + 1,X[j]);
    }
    */

    free_matrix(&matrix);

    return 0;
}
