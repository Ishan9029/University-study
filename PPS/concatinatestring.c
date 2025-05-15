#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str3[200];
    int len1, len2, result;

    // Input for the first string
    printf("Enter the first string: ");
    scanf("%99s", str1);

    // Input for the second string
    printf("Enter the second string: ");
    scanf("%99s", str2);

    // Concatenate str1 and str2
    strcpy(str3, str1);
    strcat(str3, str2);

    // Compare str1 and str2
    result = strcmp(str1, str2);

    // Find the length of str1 and str2
    len1 = strlen(str1);
    len2 = strlen(str2);

    // Display results
    printf("First String Concatenated to Second String: %s\n", str3);
    printf("Comparison result: %d\n", result);
    printf("Length of the first string: %d\n", len1);
    printf("Length of the second string: %d\n", len2);

    return 0;
}
