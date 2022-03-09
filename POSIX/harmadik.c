#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>



int main(int argc, char* argv[]){

    srand(time(NULL));

    float random_num = rand()%9 + 1;
    float random_tort = rand()%500 + 1;
    random_num = random_num + random_tort * 0.01;

    printf("%f",random_num);
    
    return 0;
}