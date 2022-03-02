#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MERET 8
void prefix(int tomb[]);
void crew_prefix(int tomb[]);
void erew_prefix(int tomb[]);

int main(){

    int tomb[MERET];
    srand(time(NULL));

    for (int i = 0; i < MERET; i++)
    {
        tomb[i] = rand() % 100 + 1;
        printf("%d ",tomb[i]);
    }
    
    printf("\n");
    printf("Sima: ");
    
    prefix(tomb);

    printf("\n");
    printf("Crew_prefix: ");

    crew_prefix(tomb);

    printf("\n");
    printf("Erew_prefix: ");

    erew_prefix(tomb);


    return 0;
}

void prefix(int tomb[]){
    int osszeg = tomb[0];
    int tomb2[MERET];
    tomb2[0] = osszeg;

    for (int j = 1; j < MERET; j++)
    {
        osszeg += tomb[j];
        tomb2[j] = osszeg;
    }

    for (int i = 0; i < MERET; i++)
    {
        printf("%d ",tomb2[i]);
    }
}
void crew_prefix(int tomb[]){
    int tomb2[MERET];
    int elso = MERET / 2;
    tomb2[0] = tomb[0];
    int osszeg = tomb[0];
    for (int j = 1; j < elso; j++)
    {
        osszeg += tomb[j];
        tomb2[j] = osszeg;
    }
    tomb2[elso] = tomb[elso];
    osszeg = tomb[elso];
    for (int i = elso + 1; i < MERET; i++)
    {
        osszeg += tomb[i];
        tomb2[i] = osszeg;
    }
    for (int i = elso; i < MERET; i++)
    {
        tomb2[i] += tomb2[elso - 1];
    }
       
    for (int k = 0; k < MERET; k++)
    {
        printf("%d ",tomb2[k]);
    }
     
}
void erew_prefix(int tomb[]){
    int tomb2[MERET];
    tomb2[0] = tomb[0];
    for (int i = 1; i < MERET; i++)
    {
        tomb2[i] = tomb[i - 1] + tomb[i];
    }
    int k = 1;
    while (k < MERET)
    {
        for (int i = k + 1; i < MERET; i++)
        {
            tomb2[i] = tomb2[i - k] + tomb2[i];
        }
        k *= 2;
        
    }
    for (int k = 0; k < MERET; k++)
    {
        printf("%d ",tomb2[k]);
    }
    
    

}