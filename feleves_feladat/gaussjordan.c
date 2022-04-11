#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3
#define MAX_NO_OF_THREADS 4

typedef struct arg_data
{
	int thread_count;
	int thread_number;

	double a[N][N+1];
	
	int n; 

	int rs; 
	int re; 
} arg_data;

void* work(void* arg){

	arg_data* current_thread_data = (arg_data*)arg;

	
	
	
	
	return NULL;
}

int main(){
   	double matrix[N][N+1] = {{1,1,-1,7},{1,-1,2,3},{2,1,1,9}};

    pthread_t threads[MAX_NO_OF_THREADS];

    arg_data arg_data[MAX_NO_OF_THREADS];

    int no_of_threads = MAX_NO_OF_THREADS;
    printf("Creating %d number of threads...\n", no_of_threads);

    int rowPerthr = N / MAX_NO_OF_THREADS;

    for (int i = 0; i < MAX_NO_OF_THREADS; i++)
	{
		arg_data[i].thread_number = i;
		arg_data[i].thread_count = MAX_NO_OF_THREADS;
		arg_data[i].n = N;
		
		if(i == MAX_NO_OF_THREADS - 1)
		{
		    arg_data[i].rs = i * rowPerthr;
		    arg_data[i].re = N - 1;
		}
		else
		{
		    arg_data[i].rs = i * rowPerthr;
		    arg_data[i].re = (i + 1)*rowPerthr - 1;
		  
		}
 	}

	for (int i = 0; i < MAX_NO_OF_THREADS; i++)
	{
		pthread_create(&threads[i], NULL, work, &arg_data[i]);
	}
	for (int i = 0; i <= MAX_NO_OF_THREADS; i++){
		pthread_join(threads[i], NULL);
	}
        
	 


    return 0;
}