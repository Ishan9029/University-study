#include <stdio.h>

int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = 10, ch, pos, elem, i;

    do
    {
        printf("\033[H\033[J");
        printf("------------------------------");
        printf("\n1. DELETE BY POSITION");
        printf("\n2. INSERT AT POSITION");
        printf("\n3. PRINT ARRAY ELEMENTS");
        printf("\n0. EXIT");
        printf("\n------------------------------");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter Position to Delete: ");
            scanf("%d", &pos);

            if (pos > n || pos <= 0)
            {
                printf("Invalid position! Position must be between 1 and %d", n);
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

        case 2:
            printf("Enter Position to Insert: ");
            scanf("%d", &pos);

            if (pos > n + 1 || pos <= 0)
            {
                printf("Invalid position! Position must be between 1 and %d", n + 1);
            }
            else
            {
                printf("Enter the Element to Insert: ");
                scanf("%d", &elem);

                for (i = n; i >= pos; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[pos - 1] = elem;
                n++;
                printf("Element %d inserted successfully at position %d", elem, pos);
            }
            break;

        case 3:
            printf("\nArray Elements:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\t", arr[i]);
            }
            break;

        case 0:
            return 0;

        default:
            printf("Invalid choice! Please try again.");
        }
        printf("\nPress any key to continue...");
        getchar();
        getchar();
    } while (ch != 0);

    return 0;
}
