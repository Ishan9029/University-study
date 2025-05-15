#include <stdio.h>

int main()
{
    int arr[100], ch, n, i, M, pos, j, temp;

    do
    {
        printf("\033[H\033[J");
        printf("------------------------------");
        printf("\n1. CREATE DATA");
        printf("\n2. DISPLAY DATA");
        printf("\n3. APPEND DATA");
        printf("\n4. COUNT DATA");
        printf("\n5. SEARCH BY POSITION");
        printf("\n6. UPDATE BY POSITION");
        printf("\n7. DELETE BY POSITION");
        printf("\n8. REVERSE DATA");
        printf("\n9. SORT DATA BY ASCENDING");
        printf("\n10. SORT DATA BY DESCENDING");
        printf("\n0. EXIT");
        printf("\n------------------------------");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter how many numbers you want: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++)
            {
                printf("Enter Number %d : ", i + 1);
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            printf("\nYour Data\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 3:
            printf("Enter how many more numbers you want: ");
            scanf("%d", &M);

            for (i = n; i < n + M; i++)
            {
                printf("Enter Number: ");
                scanf("%d", &arr[i]);
            }
            n = n + M;
            break;
        case 4:
            printf("\nTotal number of data = %d", n);
            break;
        case 5:
            printf("Enter Position to Search: ");
            scanf("%d", &pos);

            if (pos > n)
            {
                printf("Position must be less than or equal to %d", n);
            }
            else
            {
                printf("Element at %d Position = %d", pos, arr[pos - 1]);
            }
            break;
        case 6:
            printf("Enter Position to Update: ");
            scanf("%d", &pos);

            if (pos > n)
            {
                printf("Position must be less than or equal to %d", n);
            }
            else
            {
                printf("Element at %d Position = %d", pos, arr[pos - 1]);
                printf("\nEnter New Number: ");
                scanf("%d", &arr[pos - 1]);
                printf("Element at %d Position = %d", pos, arr[pos - 1]);
            }
            break;
        case 7:
            printf("Enter Position to Delete: ");
            scanf("%d", &pos);

            if (pos > n)
            {
                printf("Position must be less than or equal to %d", n);
            }
            else
            {
                printf("%d is deleted successfully...!", arr[pos - 1]);
                for (i = pos - 1; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
            }
            break;
        case 8:
            printf("\nReverse Data\n");
            for (i = n - 1; i >= 0; i--)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 9:
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            printf("\nSorted Data\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 10:
            for (i = 0; i < n; i++)
            {
                for (j = i + 1; j < n; j++)
                {
                    if (arr[i] < arr[j])
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }

            printf("\nSorted Data\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;
        case 0:
            getchar();
            return 0;
        }
        printf("\nPress any key to continue...");
        getchar();
        getchar();
    } while (ch != 0);
    return 0;
}
