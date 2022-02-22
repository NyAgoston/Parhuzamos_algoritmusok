#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

    srand(time(NULL)); 

    int eredmeny;

    int elso = (rand() % (1000 - 500 + 1)) + 500;

    int masodik = (rand() % (1000 - 500 + 1)) + 500;

    int ertek = elso + masodik;

    printf("Adja meg %d + %d erteket: ",elso,masodik);
    clock_t begin = clock();
    scanf("%d",&eredmeny);
    if(eredmeny == ertek){
        printf("A valasz: %d\n",eredmeny);
    }
    else{
        printf("Rossz valasz!\n");
    }
    
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Eltelt ido: %.2lf masodperc!",time_spent);
   
   
   return 0;
}
