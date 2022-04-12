#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <float.h>

#define MAX_NO_OF_THREADS 4

static double solutions[10000];

typedef struct arg_data {
    int thread_number;
    int N;
    double **A;
} arg_data;

void randomfill(double **A,int N){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            A[i][k] = rand() % 100;           
        }
        
    }

}

void print(double **A,int N){
    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            printf("%lf ",A[i][k]);
        }
        printf("\n");
        
    }

}
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

void* infnorm(void* arg){
    arg_data* current_thread_data = (arg_data*)arg;
    printf("Current thread no is : %d\n", current_thread_data->thread_number);

    int endpart = (current_thread_data->thread_number) * (current_thread_data->N / MAX_NO_OF_THREADS);
    int startpart = endpart - (current_thread_data->N / MAX_NO_OF_THREADS);

    printf("Here we will sum %d to %d\n", startpart, endpart - 1);

    int N = current_thread_data->N;

    //double B[N/MAX_NO_OF_THREADS];
    double seged = 0;
    
    for (int i = startpart; i < endpart; i++)
    {
        seged = 0;
        for (int j = 0; j < N; j++)
        {
            seged += abs(current_thread_data->A[j][i]);
        }
        //B[i] = seged;
        solutions[i] = seged;
        
    }

}

int main(){

    int N = 10000;

    double **A = (double **)malloc(N*sizeof(double));
    for (int i = 0; i < N; i++)
    {
        A[i] = (double *)malloc(N*sizeof(double));
    }
    srand(time(NULL));

    randomfill(A,N);

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
        arg_data[thread_no - 1].N = N;
        arg_data[thread_no - 1].A = A;
        pthread_create(&id[thread_no - 1], NULL, infnorm, &arg_data[thread_no - 1]);
    }
    
    //joining the threads one by one
    for (int i = 1; i <= MAX_NO_OF_THREADS; i++){
        pthread_join(id[i - 1], NULL);
    }

    printf("The matrixes infinity norm is: %lf\n",max(solutions,N));

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Matrix size: %d, time taken: %lf\n",N,time_taken);

    printf("Exit...");


    return 0;
}