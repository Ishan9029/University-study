#include <stdio.h>

int main()
{
    int i, j, k, c, mat[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter the element of matrix at position %d,%d: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &k);
    for (c = 0; 0 < 2; c++)
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (mat[i][j] == k)
                {
                    printf("Element found at position %d,%d\n", i + 1, j + 1);
                    return 0;
                }
            }
        }
        printf("No Such Element In This Matrix\n");
        return 0;
    }
}
