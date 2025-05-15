#include <stdio.h>
#include <math.h>

// Function to convert a number from any base to decimal
int toDecimal(char number[], int base)
{
    int len = 0, decimal = 0, power = 0;
    
    // Find the length of the number string
    while (number[len] != '\0')
        len++;

    // Convert each digit to its decimal equivalent
    for (int i = len - 1; i >= 0; i--)
    {
        int digit;
        if (number[i] >= '0' && number[i] <= '9')
            digit = number[i] - '0';
        else if (number[i] >= 'A' && number[i] <= 'F')
            digit = number[i] - 'A' + 10;
        else if (number[i] >= 'a' && number[i] <= 'f')
            digit = number[i] - 'a' + 10;
        
        // Compute the decimal value
        decimal += digit * pow(base, power);
        power++;
    }
    
    return decimal;
}

// Corrected function to convert a decimal number to any base
void fromDecimal(int decimal, int base, char result[])
{
    if (decimal == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return;
    }

    char digits[] = "0123456789ABCDEF";
    int i = 0, j;

    while (decimal > 0)
    {
        result[i++] = digits[decimal % base];
        decimal /= base;
    }

    result[i] = '\0';  // Null-terminate the string

    // Reverse the result array
    for (j = 0; j < i / 2; j++)
    {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }
}

int main()
{
    char number[100], result[100];
    int fromBase, toBase, decimal;

    // Input for the number and bases
    printf("Enter the number to convert: ");
    scanf("%s", number);
    printf("Enter the base of the input number: ");
    scanf("%d", &fromBase);
    printf("Enter the base to convert to: ");
    scanf("%d", &toBase);

    // Convert to decimal first
    decimal = toDecimal(number, fromBase);

    // Convert from decimal to the desired base
    fromDecimal(decimal, toBase, result);

    // Display the result
    printf("The converted number is: %s\n", result);

    return 0;
}
