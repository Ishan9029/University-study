#include <stdio.h>
void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
        printf("Move disk 1 from %c to %c\n", A, C);
    else
    {
        hanoi(n - 1, A, C, B);
        printf("Move disk %d from %c to %c\n", n, A, C);
        hanoi(n - 1, B, A, C);
    }
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
