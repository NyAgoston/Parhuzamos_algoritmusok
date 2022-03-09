#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>

#define MERET 10
static int tomb[MERET] = {0,1,2,3,4,5,6,7,8,9};

void errorfgvny(void* _){
    
    sleep(1);
    for (int i = 0; i < 100; i++)
    {
        printf(tomb[i]);
    }
    
}
int main(int argc, char* argv[]){

    

    pthread_t tid;
    pthread_create(&tid,NULL,errorfgvny,NULL);
    pthread_join(tid,NULL);

    for (int i = 0; i < MERET; i++)
    {
        printf("%d\n",tomb[i]);
    }
    

    return 0;
}