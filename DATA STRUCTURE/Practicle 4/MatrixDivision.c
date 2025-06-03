#include <stdio.h>

int main()
{
    int i, j;
    double a[2][2], b[2][2], c[2][2];

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\nEnter the element of first matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%lf", &a[i][j]);
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\nEnter the element of second matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%lf", &b[i][j]);
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (b[i][j] == 0)
            {
                printf("\nError: Division by zero at position %d,%d.", i + 1, j + 1);
                return 1;
            }
            c[i][j] = a[i][j] / b[i][j];
        }
    }

    printf("\nThe Division of the two matrices is:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%lf\t", c[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
