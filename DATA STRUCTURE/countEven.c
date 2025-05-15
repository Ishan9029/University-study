#include <stdio.h>
int main()
{
    int n = 0, i, sumeven = 0, sumnum = 0;
    for (i = 1; i <= 200; i++)
    {
        sumnum += i;
        if (i % 2 == 0)
        {
            sumeven += i;
            n = n + 1;
        }
    }
    printf("Sum of All Numbers From 1 to 200 -: %d\n", sumnum);
    printf("Sum of All Even Numbers From 1 to 200 -: %d\n", sumeven);
    printf("Number of Even numbers From 1 to 200 -: %d\n", n);
    return 0;
}