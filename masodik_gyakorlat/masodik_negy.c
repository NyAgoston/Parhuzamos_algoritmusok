#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char karakterek[36] = "ABCDEFGHIJKLMNOPQRSTUWXYZ0123456789";

    char file_name[10] = "******";

    char kiterjeszets[4] = ".txt";

    srand(time(NULL));


    for (int i = 0; i < 6; i++)
    {
        int random = rand() % (35 - 0 + 1) + 0;
        printf("%d ",random);
        file_name[i] = karakterek[random];
        
    }
    strncat(file_name, &kiterjeszets, 4);

    printf("\n");
    printf("A file neve: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c",file_name[i]);
    }
    FILE *fp;

    fopen(file_name,"w");
    fprintf(fp,"Mukodj");

    fclose(fp);
    

    return 0;
}