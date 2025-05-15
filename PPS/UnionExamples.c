// Write a program to show programming examples with union.
#include <stdio.h>
#include <string.h> // Include string.h for strcpy

// Define a union named Data
union Data {
    int intVal;
    float floatVal;
    char strVal[20];
};

int main()
{
    union Data data;

    // Example 1: Store an integer
    data.intVal = 42;
    printf("Stored integer value: %d\n", data.intVal);

    // Example 2: Store a float
    data.floatVal = 3.14;
    printf("Stored float value: %.2f\n", data.floatVal);

    // Example 3: Store a string
    strcpy(data.strVal, "Hello, World!");
    printf("Stored string value: %s\n", data.strVal);

    // Observation: Displaying other union members may yield unexpected results
    printf("Stored integer value (after string assignment): %d\n", data.intVal);
    printf("Stored float value (after string assignment): %.2f\n", data.floatVal);

    return 0;
}
