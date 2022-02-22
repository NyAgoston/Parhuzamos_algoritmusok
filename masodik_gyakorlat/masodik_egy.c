#include <stdio.h>
#include <time.h>

void osszeg(int tomb[], int meret);
void max(int tomb[], int meret);
void min(int tomb[], int meret);
int maximum(int tomb[], int index, int len);
int minimum(int tomb[], int index, int len);
#define MAX_SIZE 100
int main() {
    int tomb[MAX_SIZE];
    int meret;

    printf("Add meg a tomb meretet: ");
    scanf("%d", &meret);
    printf("Adj meg %d db elemet: ", meret);
    for(int i = 0; i < meret; i++)
    {
        scanf("%d", &tomb[i]);
    }

    
    int maximum_rekurziv;
    int minimum_rekurziv;
    

    osszeg(tomb,meret);
    clock_t begin_linear = clock();
    max(tomb,meret);
    min(tomb,meret);
    clock_t end_linear = clock();


    clock_t begin_recursive = clock();
    maximum_rekurziv = maximum(tomb,0,meret);
    printf("A legnagyobb elem rekurzivan: %d\n", maximum_rekurziv);

    minimum_rekurziv = minimum(tomb,0,meret);
    printf("A legkisebb elem rekurzivan: %d\n", minimum_rekurziv);
    clock_t end_recursive = clock();

    double time_spent_linear = (double)(end_linear - begin_linear) / CLOCKS_PER_SEC;
    printf("A lineáris keresés ideje: %lf masodperc",time_spent_linear);

    double time_spent_rec = (double)(end_recursive - begin_recursive) / CLOCKS_PER_SEC;
    printf("A rekurziv keresés ideje: %lf masodperc",time_spent_rec);

   return 0;
}
void osszeg(int tomb[], int meret){
    int osszeg = 0;

    for (int i = 0; i < meret; i++)
    {
        osszeg += tomb[i];
    }
    
    printf("A tomb osszege: %d\n",osszeg);
}

void max(int tomb[], int meret){
    int max = tomb[0];

    for (int i = 1; i < meret; i++)
    {
        if(tomb[i] > max){
            max = tomb[i];
        }
    }
    printf("A legnagyobb elem: %d\n",max);
}
void min(int tomb[], int meret){
    int min = tomb[0];

    for (int i = 1; i < meret; i++)
    {
        if(tomb[i] < min){
            min = tomb[i];
        }
    }
    printf("A legnagyobb elem: %d\n",min);
}
int maximum(int tomb[], int index, int len)
{
    int max;
    if(index >= len-2)
    {
        if(tomb[index] > tomb[index + 1])
            return tomb[index];
        else
            return tomb[index + 1];
    }

    max = maximum(tomb, index + 1, len);

    if(tomb[index] > max)
        return tomb[index];
    else
        return max;
}
int minimum(int tomb[], int index, int len)
{
    int min;

    if(index >= len-2)
    {
        if(tomb[index] < tomb[index + 1])
            return tomb[index];
        else
            return tomb[index + 1];
    }

    min = minimum(tomb, index + 1, len);

    if(tomb[index] < min)
        return tomb[index];
    else
        return min;
}
