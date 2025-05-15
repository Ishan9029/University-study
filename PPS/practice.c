#include <stdio.h>

int main() {
    int N, i;
    int sumEven = 0, sumOdd = 0;

    // Input from user
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Calculate the sum of even and odd numbers
    for (i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sumEven += i;
        } else {
            sumOdd += i;
        }
    }

    // Display results
    printf("Sum of even numbers from 1 to %d: %d\n", N, sumEven);
    printf("Sum of odd numbers from 1 to %d: %d\n", N, sumOdd);

    return 0;
}
