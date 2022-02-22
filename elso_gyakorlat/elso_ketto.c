#include <stdio.h>
int main() {
   
   int szam = 6;

   printf("0-akkal: %.8d\n",szam);

   printf("Szokozokkel:");

   for(int i = 0; i < 8; i++)
   {
      printf(" ");
   }
   printf("%d",szam);
   
   return 0;
}
