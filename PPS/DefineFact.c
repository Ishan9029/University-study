//Define a function named fact () to calculate factorial of a number n.
#include <stdio.h>

// Function to calculate factorial of a number
int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int number, result;

    // Input for the number
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &number);

    // Calculate the factorial
    result = fact(number);

    // Display the result
    printf("The factorial of %d is: %d\n", number, result);

    return 0;
}
