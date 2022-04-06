#include <stdio.h>
#include <stdlib.h>

#define MERET 10

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[MERET],int p, int r,int x){
    int i = p - 1;
    int j = r + 1;

    while (i < j) {
        do {
            ++i;
        }while (array[i] < x);
        do {
        --j;
        }while (array[j] > x);
            if (i < j) {
            swap(&array[i],&array[j]);
            }
  }

  return j;

}
void quicksort(int array[MERET], int p, int r)
{
  int q;

  if (p < r) {
    q = partition(array, p, r, array[p]);
    quicksort(array, p, q);
    quicksort(array, q + 1, r);
  }
}

int main(){
    int array[MERET] = {64, 34, 25, 12, 22, 11, 90};
    quicksort(array,0,MERET - 1);
    for (int i = 0; i < MERET; ++i) {
        printf("%d ",array[i]);
    }


    return 0;
}