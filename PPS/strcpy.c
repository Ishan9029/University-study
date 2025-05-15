#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];

    // Input for the source string
    printf("Enter the First string: ");
    scanf("%s", str1);  // Using scanf to input string

    // Using strcpy to copy the source string to the destination string
    strcpy(str2, str1);

    // Display the copied string
    printf("First String : %s\nSecond String : %s\n",str1, str2);

    return 0;
}
