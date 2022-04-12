#include <stdio.h>
#include <stdlib.h>
<<<<<<< Updated upstream
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
=======

#define N 3

int main()
{
    float matrix[20][20];
    float c,x[N+1];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= (N + 1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&matrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%f ",matrix[i][j]);
        }
        printf("\n");
        
    }
    for(int j=1; j<=N; j++)
    {
        for(int i=1; i<=N; i++)
        {
            if(i!=j)
            {
                c = matrix[i][j] / matrix[j][j];
                printf("c:%f\n",c);
                for(int k=1; k<=N + 1; k++)
                {
                    matrix[i][k] = matrix[i][k] - c * matrix[j][k];
                }
            }
        }
    }
    printf("\nA megoldas:\n");
    for(int l = 1; l <= N; l++)
    {
        x[l] = matrix[l][N+1] / matrix[l][l];
        printf("\n x%d=%f\n",l,x[l]);
    }  
    
    return(0);
>>>>>>> Stashed changes
}