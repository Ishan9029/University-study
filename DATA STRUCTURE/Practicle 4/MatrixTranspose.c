#include <stdio.h>

int main()
{
    int i, j;
    int a[2][2], transpose[2][2];

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\nEnter the element of the matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    // Calculate transpose of the matrix
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transpose[j][i] = a[i][j];
        }
    }

    printf("\nThe Transpose of the matrix is:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
