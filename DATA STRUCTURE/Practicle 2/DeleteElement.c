#include <stdio.h>
int main()
{
    int pos, i, ch, size, n;
    int arr[100];
start:
    printf("\033[H\033[J");
    printf("-------------------------\n");
    printf("1. Create an Array\n");
    printf("2. Insert Elements in Array\n");
    printf("3. Delete Element By Position\n");
    printf("4. Update Element By Position\n");
    printf("5. Display Elements of Arrray\n");
    printf("0. Exit\n");
    printf("-------------------------\n");
    printf("Enter Choice -: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("\033[H\033[J");
        printf("Enter Size of Array -: ");
        scanf("%d", &size);
        for (i = 0; i < size; i++)
        {
            printf("Enter Element %d of Array -: ", i + 1);
            scanf("%d", &arr[i]);
        }
        printf("Array has Been Created...");
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    case 2:
        printf("\033[H\033[J");
        printf("How Many Elements Do you Wish To Enter -: ");
        scanf("%d", &n);
        size = size + n;
        for (i = 0; i < n; i++)
        {
            printf("Enter Element %d -: ", i + 1);
            scanf("%d", &arr[size + i]);
        }
        printf("Elements Have Been Inserted In Array...");
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    case 3:
        printf("\033[H\033[J");
        printf("Enter Position To Be Deleated -: ");
        scanf("%d", &pos);
        for (i = pos - 1; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        printf("Element has Been Deleted...!");
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    case 4:
        printf("\033[H\033[J");
        printf("Enter Position To Be Updated -: ");
        scanf("%d", &pos);
        printf("Enter Element -: ");
        scanf("%d", &arr[pos - 1]);
        printf("Element has been Updated....!");
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    case 5:
        printf("\033[H\033[J");
        printf("Array Elements : ");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    case 0:
        printf("\033[H\033[J");
        return 0;
    default:
        printf("Invalid Choice!!! Try Again");
        printf("\nEnter Any key to continue....!");
        getchar();
        getchar();
        goto start;
    }
}