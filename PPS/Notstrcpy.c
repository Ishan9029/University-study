#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i;

    // Input for the source string
    printf("Enter the First string: ");
    scanf("%s", str1);  // Using scanf to input string

    // Manually copying the source string to the destination string
    for(i = 0; str1[i] != '\0'; i++)
    {
        str2[i] = str1[i];
    }
    str2[i] = '\0'; // Null-terminate the destination string

    // Display the copied string
    printf("First String : %s\nSecond String : %s\n",str1, str2);

    return 0;
}
