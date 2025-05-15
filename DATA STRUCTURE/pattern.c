#include <stdio.h>
int main()
{
    int a[100], i, n;
    printf("How Many Integers Do you Wish to Enter -: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter Integer %d -: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Elements -: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d,", a[i]);
        if ((i + 1) % 3 == 0)
        {
            printf("\n");
        }
    }
    return 0;
}