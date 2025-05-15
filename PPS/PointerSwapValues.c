//Write a program to swap value of two variables using pointer
#include <stdio.h>

// Function to swap values of two variables using pointers
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int num1, num2;

    // Input for the two variables
    printf("Enter the value of the first variable: ");
    scanf("%d", &num1);
    printf("Enter the value of the second variable: ");
    scanf("%d", &num2);
    
    // Display initial values
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Call function to swap the values
    swap(&num1, &num2);

    // Display the swapped values
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}
