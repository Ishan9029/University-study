#include <stdio.h>
int main()
{
    int a[100][100], b[100][100], c[100][100], i, j, k, l, m, n;
    printf("Enter Row of First Matrix -: ");
    scanf("%d", i);
    printf("Enter Column of Second Matrix -: ");
    scanf("%d", j);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter Element %d,%d of First Array -: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("Enter Element %d,%d of Second Array -: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 2; k++)
            {
                c[i][j] *= a[i][k] + b[k][j];
            }
        }
    }
    printf("\n\n");
    printf("Product Of Both Array -: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}