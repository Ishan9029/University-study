#include <stdio.h>
int main()
{
    int i,n,a;
    printf("Enter a No -: ");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            a=1;
        }     
    }
    if(a==0)
    printf("THe No is PRIME");
    else
    printf("The No is NOT PRIME");
    return 0;
}