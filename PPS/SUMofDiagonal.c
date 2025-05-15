#include <stdio.h>
int main()
{
    int m, n, i, j;
    
    // Input for the order of the matrix
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    int sum = 0;

    // Input for matrix A
    printf("Enter elements of the matrix:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("Enter Element [%d%d] --->  ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate the sum of diagonal elements
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if (i == j) sum += a[i][j];     // Primary diagonal
            if ((i + j) == (n-1)) sum += a[i][j]; // Secondary diagonal
        }
    }

    // Display the sum of diagonal elements
    printf("The SUM of the diagonals is ---> %d\n", sum);
    
    return 0;
}
