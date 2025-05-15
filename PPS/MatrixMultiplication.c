#include <stdio.h>

int main()
{
    int m, n, p, q, i, j, k;

    // Input the order of the first matrix
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &m, &n);
    
    // Input the order of the second matrix
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Matrix multiplication not possible with the given orders!\n");
        return -1;
    }

    int a[m][n], b[p][q], c[m][q];

    // Input for matrix A
    printf("Enter elements of the first matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter Element [%d%d] --->  ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
    
    // Input for matrix B
    printf("Enter elements of the second matrix:\n");
    for(i = 0; i < p; i++)
    {
        for(j = 0; j < q; j++)
        {
            printf("Enter Element [%d%d] --->  ", i+1, j+1);
            scanf("%d", &b[i][j]);
        }
    }

    // Initializing elements of matrix c to 0
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
        {
            c[i][j] = 0;
        }
    }

    // Multiplying matrices a and b and storing the result in c
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
        {
            for(k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the result
    printf("The PRODUCT of both matrices is ---> \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < q; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
