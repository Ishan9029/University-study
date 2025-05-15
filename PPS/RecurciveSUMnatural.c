// Write a program to calculate sum of first 50 natural numbers using recursive function

#include <stdio.h>

// Function to calculate sum of natural numbers recursively
int sumOfNaturalNumbers(int n)
{
    if (n <= 1)
        return n;
    else
        return n + sumOfNaturalNumbers(n - 1);
}

int main()
{
    int sum;

    // Calculate the sum of the first 50 natural numbers
    sum = sumOfNaturalNumbers(50);

    // Display the result
    printf("The sum of the first 50 natural numbers is: %d\n", sum);

    return 0;
}
