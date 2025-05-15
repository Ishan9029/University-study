#include <stdio.h>

int main()
{
    int i, j, k, l, m, n, o;
    int a[100][100], b[100][100], c[100][100];
start:
    printf("Enter the No of Rows of First matrix -: ");
    scanf("%d", &l);
    printf("Enter the No of Columns of First matrix -: ");
    scanf("%d", &m);
    printf("Enter the No of Rows of Second matrix -: ");
    scanf("%d", &n);
    printf("Enter the No of Columnsof Second matrix -: ");
    scanf("%d", &o);
    if (m != n)
    {
        printf("No of Columns of First matrix Should Be Equal To The No of Rows Of Second matrix....");
        goto start;
    }
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("\nEnter the element of first matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < o; j++)
        {
            printf("\nEnter the element of second matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < o; j++)
        {
            c[i][j] = 0; // Initialize the result matrix
            for (k = 0; k < m; k++)
            {
                c[i][j] += a[i][k] * b[k][j]; // Perform matrix multiplication
            }
        }
    }
    printf("\nThe Product of the two matrices is:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n\n");
    }
    return 0;
}
