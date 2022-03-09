#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>


const int N_THREADS = 60;

void wait_onesec(void* _){
    pid_t tid;
    printf("[%d] wait %d second",tid,1);
    sleep(1);
}
int main(int argc, char* argv[]){

    pthread_t szalak[N_THREADS];
    for (int i = 0; i < N_THREADS; i++)
    {
        pthread_create(&szalak[i],NULL,wait_onesec,NULL);
    }
    for (int i = 0; i < N_THREADS; i++)
    {
        pthread_join(szalak[i],NULL);
    }
    
    


    return 0;
}