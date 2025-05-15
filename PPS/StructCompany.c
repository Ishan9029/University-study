#include <stdio.h>

// Define the structure named company
struct company {
    char name[50];
    char address[100];
    char phone[15];
    int noOfEmployees;
};

int main()
{
    struct company comp;

    // Input for the company details
    printf("Enter the name of the company: ");
    scanf("%s", comp.name);
    
    printf("Enter the address of the company: ");
    scanf("%s", comp.address);
    
    printf("Enter the phone number of the company: ");
    scanf("%s", comp.phone);
    
    printf("Enter the number of employees in the company: ");
    scanf("%d", &comp.noOfEmployees);

    // Display the company details
    printf("\nCompany Details:\n");
    printf("Name: %s\n", comp.name);
    printf("Address: %s\n", comp.address);
    printf("Phone: %s\n", comp.phone);
    printf("Number of Employees: %d\n", comp.noOfEmployees);

    return 0;
}
