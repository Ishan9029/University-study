#include <stdio.h>
int main()
{
    int x, y;
    char i;
    printf("Enter the First Number -: ");
    scanf("%d", &x);
    printf("Enter the Second Number -: ");
    scanf("%d", &y);
    printf("Enter an Operator (+, -, *, /) -: ");
    scanf(" %c", &i); // Corrected format specifier and added space to handle newline

    switch (i)
    {
    case '+':
        printf("Ans -: %d", x + y);
        break;
    case '-':
        printf("Ans -: %d", x - y);
        break;
    case '*':
        printf("Ans -: %d", x * y);
        break;
    case '/':
        if (y == 0)
        {
            printf("Error: Division by zero is not allowed.");
        }
        else
        {
            printf("Ans -: %d", x / y);
        }
        break;
    default:
        printf("Invalid Operator");
    }
    return 0;
}