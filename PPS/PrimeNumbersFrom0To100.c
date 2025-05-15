// To print all prime no from 0 to 100
#include <stdio.h>

int main() 
{
    int a, i, Prime;

    printf("Prime numbers from 0 to 100 are:\n");

    for (a = 2; a <= 100; a++) 
    {
        Prime = 1; // Assume number is prime

        for (i = 2; i * i <= a; i++) 
        {
            if (a % i == 0) 
            {
                Prime = 0; // Number is not prime
                break;
            }
        }

        if (Prime == 1) 
        {
            printf("%d ", a);
        }
    }

    printf("\n");

    return 0;
}
