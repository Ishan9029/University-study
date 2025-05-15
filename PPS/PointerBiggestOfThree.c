//. Write a program to find biggest among three numbers using pointer
#include <stdio.h>

void findLargest(int *a, int *b, int *c, int *largest)
{
    if (*a > *b && *a > *c)
        *largest = *a;
    else if (*b > *a && *b > *c)
        *largest = *b;
    else
        *largest = *c;
}

int main()
{
    int num1, num2, num3, largest;

    // Input for three numbers
    printf("Enter three numbers:\n");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Call function to find the largest number using pointers
    findLargest(&num1, &num2, &num3, &largest);

    // Display the largest number
    printf("The largest number is: %d\n", largest);

    return 0;
}
