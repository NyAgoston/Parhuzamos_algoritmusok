#include <stdio.h>
int main()
{
    int i,j,k,n;
    float A[4][5],c,x[10];
    printf("\nEnter the size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf(" A[%d][%d]:", i,j);
            scanf("%f",&A[i][j]);
        }
    }
<<<<<<< Updated upstream
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
=======
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
>>>>>>> Stashed changes
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
        
    }
    
<<<<<<< Updated upstream
    
    
=======
>>>>>>> Stashed changes
    /* Now finding the elements of diagonal matrix */
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
    }
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
<<<<<<< Updated upstream
                printf("%f",c);
=======
                printf("c:%f\n",c);
>>>>>>> Stashed changes
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    printf("Utana\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%f ",A[i][j]);
        }
        printf("\n");
        
    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}