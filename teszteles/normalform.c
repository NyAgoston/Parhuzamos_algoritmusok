#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <pthread.h>

#define N 100
#define MAX_NO_OF_THREADS 4

static int A[N][N];

static int sorok[N];

typedef struct arg_data
{
	int thread_count;
	int thread_number;
	
	int n; 

	int rs; 
	int re; 
} arg_data;

void* work(void* arg){
    arg_data* current_thread_data = (arg_data*)arg;

    printf("Here we will sum %d to %d\n", current_thread_data->rs, current_thread_data->re);
    
    for (int i = current_thread_data->rs; i < current_thread_data->re; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            sorok[k] += abs(A[i][k]);
        }
    }


    return NULL;
}

void max(){
    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if(sorok[i]>max){
            max = sorok[i];
        }
    }
    printf("The matrixes infinity norm: %d",max);
    
}

int main(){

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        
        for (int k = 0; k < N; k++)
        {
            A[i][k] = rand() % 100;
        }
        
    }

    pthread_t threads[MAX_NO_OF_THREADS];

    arg_data arg_arr[MAX_NO_OF_THREADS];

    int no_of_threads = MAX_NO_OF_THREADS;
    printf("Creating %d number of threads...\n", no_of_threads);

    int rowPerthr = N / MAX_NO_OF_THREADS;

    for (int i = 0; i < MAX_NO_OF_THREADS; i++)
	{
		arg_arr[i].thread_number = i;
		arg_arr[i].thread_count = MAX_NO_OF_THREADS;
		arg_arr[i].n = N;
		
		if(i == MAX_NO_OF_THREADS - 1)
		{
		    arg_arr[i].rs = i * rowPerthr;
		    arg_arr[i].re = N - 1;
		}
		else
		{
		    arg_arr[i].rs = i * rowPerthr;
		    arg_arr[i].re = (i + 1)*rowPerthr - 1;
		  
		}
 	}

    for (int i = 0; i < MAX_NO_OF_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, work, &arg_arr[i]);
	}
	for (int i = 0; i <= MAX_NO_OF_THREADS; i++){
        pthread_join(threads[i], NULL);
    }


    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if(sorok[i]>max){
            max = sorok[i];
        }
    }
    printf("The matrixes infinity norm: %d",max);
    
    



    
    
    
    
    return 0;
}