#include <stdio.h>
#include "sum.h"

int main()
{
    int a, b;
    printf("Enter The First Number -: ");
    scanf("%d", &a);
    printf("Enter The Second Number -: ");
    scanf("%d", &b);
    printf("The Sum of both numbers is -: %d\n", sum(a, b));
    return 0;
}