#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the First Number -: ");
    scanf("%d",&a);
    printf("Enter the second Number -: ");
    scanf("%d",&b);
    printf("Enter the third Number -: ");
    scanf("%d",&c);
    if(a>b)
    {
        if(a>c)
        {
            printf("The Largest Number is %d",a);
        }
        else
        {
            printf("The Largest Number is %d",c);
        }
    }
    else
    {
        if(b>c)
        {
            printf("The Largest Number is %d",b);
        }
        else
        {
            printf("The Largest Number is %d",c);
        }     
    }
    return 0;
}