#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix_operations.h"

int main(){

    Matrix matrix;

    alloc_matrix(&matrix,3,4);

    int N = matrix.N;

    srand(time(NULL));

    randomfill_matrix(&matrix);
    
    print_matrix(&matrix);

    clock_t start,end;
    double time_taken;

    start = clock();


    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf",N,time_taken);

    free_matrix(&matrix);

    return 0;
}
