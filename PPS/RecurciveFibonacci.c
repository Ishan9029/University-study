// Write a recursive function to generate Fibonacci series.
#include <stdio.h>

// Function to calculate Fibonacci number at position n
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    // Input for the number of terms
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    // Display the Fibonacci series
    printf("Fibonacci series:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
