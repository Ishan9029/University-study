// To Print all ODD Numbers between two Numbers using FOR Loop
#include <stdio.h>
int main()
{
    int i,x,y,z;
    printf("Enter the First Number --->\t");
    scanf("%d",&x);
    printf("Entere the Second Number --->\t");
    scanf("%d",&y);
    if(x==y)
    {
        printf("INVALID!\nSECOND NUMBER SHOULD BE GREATER THAN FIRST NUMBER");
        return 0;
    }
    if(x>y)
    {
        printf("INVALID!\nSECOND NUMBER SHOULD BE GREATER THAN FIRST NUMBER");
    }
    if(y==x+1)
    {
        printf("INVALID!\nTHERE ARE NO ODD NUMBERS BETWEEN THEM");\
        return 0;
    }
    if(x%2==0)
    {
        z=x+1;
    }
    else
    {
        z=x+2;
    }
    for(i=z;i<y;)
    {
        printf("%d\n",i);
        i=i+2;
    }
    return 0;
}