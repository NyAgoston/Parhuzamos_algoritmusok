#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <time.h>

#define MERET 100

static int tomb[MERET];

static int primek = 0;

void feltolt();
void prim_tomb();
void prim(int n);

int main(int argc, char* argv[]){

    feltolt();

    prim_tomb();

    printf("Primek szama a tombben: %d",primek);
    return 0;
    
}
void feltolt(){
    for (int i = 0; i < MERET; i++)
    {
        tomb[i] = i;
    }
}
void prim_tomb(){
    for (int i = 0; i < MERET; i++)
    {
        prim(tomb[i]);
    }
    
}
void prim(int n){


    int i, flag = 0;

    if (n == 0 || n == 1)
    flag = 1;

    for (i = 2; i <= n / 2; ++i) {

        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0){
        primek += 1;
    } 
}