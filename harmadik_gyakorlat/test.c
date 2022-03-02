#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MERET 10

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(int tomb[])
{
	int sum = 0;
    for (int  i = 0; i < MERET; i++)
    {
        sum += tomb[i];
    }
    printf("Tomb osszege: %d",sum);
	return NULL;
}

int main()
{
	
    int tomb[MERET] = {1,2,3,4,5,6,7,8,9,10};
    
    pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun(tomb), NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}
