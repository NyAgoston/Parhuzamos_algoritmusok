#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <float.h>
#include "matrix_operations.h"

static Matrix matrix;
static double *maxes;
volatile int MAX_NO_OF_THREADS = 12;

typedef struct arg_data {
    int thread_number;
    int N;
    double *solutions;
} arg_data;

void* infnorm(void* arg){
    arg_data* current_thread_data = (arg_data*)arg;
    printf("Current thread no is : %d\n", current_thread_data->thread_number);

    int endpart = (current_thread_data->thread_number) * (current_thread_data->N / MAX_NO_OF_THREADS);
    int startpart = endpart - (current_thread_data->N / MAX_NO_OF_THREADS);

    printf("Here we will sum %d to %d\n", startpart, endpart - 1);

    int N = current_thread_data->N;
    current_thread_data->solutions = (double *)malloc(current_thread_data->N*sizeof(double));

    //double B[N/MAX_NO_OF_THREADS];
    double seged = 0;
    
    for (int i = startpart; i < endpart; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(matrix.data[i][j]);
        }
        //B[i] = seged;
        current_thread_data->solutions[i] = seged;
    }
    maxes[current_thread_data->thread_number] = max(current_thread_data->solutions,endpart);

}

int main(){

    int range = 39;

    int measures[39] = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000,10500,11000,11500,12000,12500,13000,13500,14000,14500,15000,15500};

    for (int i = 0; i < range; i++)
    {
        int size = measures[i];

        alloc_matrix(&matrix,size,size);
        maxes = (double *)malloc(MAX_NO_OF_THREADS*sizeof(double));

        int N = matrix.N;
    
        srand(time(NULL));

        randomfill_matrix(&matrix);

        //print(A,N);

        pthread_t id[MAX_NO_OF_THREADS];
        
        arg_data arg_data[MAX_NO_OF_THREADS];

        int no_of_threads = MAX_NO_OF_THREADS;
        printf("Creating %d number of threads...\n", no_of_threads);

        int thread_no = 1;

        clock_t start,end;
        double time_taken;

        start = clock();

        for (thread_no = 1; thread_no <= MAX_NO_OF_THREADS; thread_no++) {
            arg_data[thread_no - 1].thread_number = thread_no;
            arg_data[thread_no - 1].N = matrix.N;
            pthread_create(&id[thread_no - 1], NULL, infnorm, &arg_data[thread_no - 1]);
        }
        
        //joining the threads one by one
        for (int i = 1; i <= MAX_NO_OF_THREADS; i++){
            pthread_join(id[i - 1], NULL);
        }

        //printf("The matrixes infinity norm is: %lf\n",max(&maxes,N));

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Matrix size: %d, time taken: %lf\n",matrix.N,time_taken);

        free_matrix(&matrix);
        free(maxes);

        FILE *fp;
        fp = fopen("data.csv","a");

        fprintf(fp,"%d %d %lf\n",12,N,time_taken);

        fclose(fp);

        printf("Exit...");
    }
    

    


    return 0;
}