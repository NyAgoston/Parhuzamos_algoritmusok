#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int random(int tomb[]);
void egyediseg(int tomb[]);
#define MERET 10

int main() {
   
    int tomb[MERET];
    srand(time(NULL));
    
    clock_t begin = clock();
    for (int i = 0; i < MERET; i++)
    {
        tomb[i] = random(tomb);
    }
    clock_t end = clock();
    for (int i = 0; i < MERET; i++)
    {
        printf("%d ",tomb[i]);
    }

    printf("\n");

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Eltelt ido: %lf masodperc\n", time_spent);


    egyediseg(tomb);

    return 0;
}
int random(int tomb[]){
    
    int valto;
    int szam;
    do
    {
        valto = 1;
       
        szam = (rand() % (20 - 1)) + 1;
        for (int i = 0; i < MERET; i++)
        {
            if(rand() % 2 == 1){// 50% esély a duplikálásra
                valto = 1;
            }
            else if(szam == tomb[i]){
                valto = 0;
            }
        } 
    } while (!valto);

    return szam;
    
}
void egyediseg(int tomb[]){
    int valto = 0;
    
    for (int i = 0; i < MERET; i++)
    {
        for (int j = i + 1; j <= MERET; i++)
        {
            if(tomb[i] == tomb[j]){
                valto = 1;
            }
        }
    }
    
    if(valto = 0){
        printf("A tombben nincs ismetlodes!");
    }
    else{
        printf("A tombben van ismetlodes!");
    }
    
}


