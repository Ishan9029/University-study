#include <stdio.h>
int main()
{
    int a[2][2], b[2][2], c[2][2], i, j;
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
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("\n\n");
    printf("Sum Of Both Array -: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}