// To check wether a year is a leap year or not
#include <stdio.h>
int main()
{
    int year;
    printf("Enter a Year --->   ");
    scanf("%d",&year);
    if(year%400==0||(year%100!=0)&&(year%4==0))
    {
        printf("The Given Year is a leap Year");
    }
    else
    {
        printf("The Given Year is NOT a leap year");
    }
    return 0;
}