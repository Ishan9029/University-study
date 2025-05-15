#include <stdio.h>

int main()
{
    int i, size, max = 0, min = 0;
    printf("Enter size to find largest and smallest of given Numbers : \n");
    scanf("%d", &size);
    int a[100];
    for (i = 0; i < size; i++)
    {
        printf("Enter number %d in array\n", i + 1);
        scanf("%d", &a[i]);
    }
    min = a[0];
    max = a[0];
    for (i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    printf("The Largest number is %d\n", max);
    printf("The Smallest number is %d\n", min);
    return 0;
}
