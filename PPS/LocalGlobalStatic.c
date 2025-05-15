// Write a program that illustrates use of local, global and static variables
#include <stdio.h>

// Global variable
int globalVar = 0;

void demonstrateVariables()
{
    // Local variable
    int localVar = 0;

    // Static variable
    static int staticVar = 0;

    // Incrementing variables
    localVar++;
    staticVar++;
    globalVar++;

    // Display the variables
    printf("Local Variable: %d\n", localVar);
    printf("Static Variable: %d\n", staticVar);
    printf("Global Variable: %d\n", globalVar);
}

int main()
{
    int i;

    // Illustrating the use of variables over multiple function calls
    for(i = 0; i < 3; i++)
    {
        printf("\nFunction call %d:\n", i + 1);
        demonstrateVariables();
    }

    return 0;
}
