#include <stdio.h>
#include <stdlib.h> 
#include <pthread.h>

using namespace std;

typedef struct _ARGS
{
	int thread_count;
	int thread_number;

	double * a;
	double * b;
	int n; 

	int rs; 
	int re; 
} ARGS;

double getfulltime();

void *work (void *ptr)
{
	ARGS * arg = (ARGS*) ptr;
	
	int n = arg->n;	

	//int total_threads = arg->thread_count;
	   
	double tmp;
	
	int i, k, j;
	
	for (i = 0; i < n; i++)
	{
		if (i <= arg->re && i >= arg->rs)
		{
			tmp = arg->a[i*n + i];

			for (k = i; k < n; k++)
				arg->a[i*n + k] /= tmp;
			arg->b[i] /= tmp;		  
		}
	
		synchronize(arg->thread_count);
		if (i > arg->re || i < arg->rs)
		{
			for (j = arg->rs; j <= arg->re; j++)
			{
				tmp = arg->a[j * n + i];
				for (k = i; k < n; k++)
					arg->a[j*n + k] -= arg->a[i*n + k]*tmp;
				
				arg->b[j] -= arg->b[i] * tmp;
			}
			
		}
		else
		{
			for (j = arg->rs; j < i; j++)
			{
				tmp = arg->a[j * n + i];
				
				for (k = i; k < n; k++)
					arg->a[j*n + k] -= arg->a[i*n + k] * tmp;
				arg->b[j] -= arg->b[i] * tmp;
			}
			for (j = i + 1; j <= arg->re; j++)
			{
				tmp = arg->a[j * n + i];
				for (k = i; k < n; k++)
					arg->a[j*n + k] -= arg->a[i*n + k] * tmp;
				arg->b[j] -= arg->b[i] * tmp;
			}
		}
		//synchronize(arg->thread_count);
	}
	
	return NULL;
}

double solve_system(int n, double* A, double* b, double**x, int fullthr)
{
  
	pthread_t *threads;
	
	ARGS *args;
	
	int rowPerthr = n/fullthr;
	
	
	if (!(threads = (pthread_t*) malloc(fullthr * sizeof(pthread_t))))
	{
		cout<<"Thread allocation error";
		return 1;
	}
    
	if (!(args = (ARGS*) malloc (fullthr * sizeof(ARGS))))
	{
		cout<<"ARGS allocation error";
		return 1;
	}
	
	for (int i = 0; i < fullthr; i++)
	{
		args[i].thread_number = i;
		args[i].thread_count = fullthr;
		args[i].n = n;
		args[i].a = A;
		args[i].b = b;
		if(i == fullthr - 1)
		{
		    args[i].rs = i*rowPerthr;
		    args[i].re = n - 1;
		}
		else
		{
		    args[i].rs = i*rowPerthr;
		    args[i].re = (i + 1)*rowPerthr - 1;
		  
		}
 	}
    
		
	int i;	
		
	double t = getfulltime();
	
	for (i = 0; i < fullthr; i++)
		pthread_create(threads + i, 0, work, args + i);
		
	for (i = 0; i < fullthr; i++)
		pthread_join(threads[i], NULL);
	
			
	t = getfulltime() - t;

	*x = b;
	free(threads);
	free(args);
	return t;
}