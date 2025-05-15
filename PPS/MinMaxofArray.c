#include <stdio.h>
int main()
{
    int a[100],n,i,min,max;
    printf("Enter no of elements in array -: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d of Array -: ",i);
        scanf("%d",&a[i]);
    }
    min=a[0];
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("Smallest Element of Array is --->  %d\n",min);
    printf("Greatest Element of Array is --->  %d",max);
    return 0;
}