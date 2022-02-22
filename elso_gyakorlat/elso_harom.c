#include <stdio.h>
#include <unistd.h>
int main() {

    int szam;

    printf("Adja meg az idozito hosszat: ");

    scanf("%d",&szam);

    for (int i = szam; i > 0; i--)
    {
        printf("Hatravan %d masodperc\n",i);
        sleep(1);
    }
    printf("Lejart az ido!!");


   
   return 0;
}
