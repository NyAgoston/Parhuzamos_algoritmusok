#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MERET 100

typedef struct arg_data {
    int thread_number;
} arg_data;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	
	for (i = 0; i < n-1; i++)
	{


		
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx]){
			min_idx = j;
		}
			

		swap(&arr[min_idx], &arr[i]);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main()
{
	int arr[MERET];

	srand(time(NULL));

	for (int i = 0; i < MERET; i++)
	{
		arr[i] = rand() % 100;
	}
		
	selectionSort(arr, MERET);
	printf("Sorted array: \n");
	printArray(arr, MERET);
	return 0;
}
