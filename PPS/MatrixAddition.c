#include <stdio.h>
int main()
{
    int m, n, i, j;
    
    // Input for the order of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    int b[m][n];
    int sum[m][n];

    // Input for matrix A
    printf("Enter Elements of Matrix A -: \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input for matrix B
    printf("Enter Elements of Matrix B -: \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Display Matrix A
    printf("Matrix A is --->\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("\t%d\t", a[i][j]);
        }
        printf("\n\n");
    }

    // Display Matrix B
    printf("Matrix B is --->\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("\t%d\t", b[i][j]);
        }
        printf("\n\n");
    }

    // Calculate and display the sum
    printf("The SUM of both matrices is ---> \n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
            printf("\t%d\t", sum[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
