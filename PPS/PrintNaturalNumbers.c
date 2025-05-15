#include <stdio.h>
int main()
{
    int i, sum, z;
    printf("Enter the no of natural numbers to be added -: ");
    scanf("%d", &z);
    for (i = 1; i <= z; i++)
    {
        sum = sum + i;
    }
    printf("%d", sum);
    return 0;
}
