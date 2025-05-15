#include<stdio.h>
int main()
{
    int i,a=0,b=1,n,c;
    printf("Enter the Number -: ");
    scanf("%d",&n);
    printf("%d\n%d",a,b);
    for(i=3;i<=n;i++)
    {
        c=a+b;
        printf("\n%d",c);
        a=b;
        b=c;
    }
return 0;
}