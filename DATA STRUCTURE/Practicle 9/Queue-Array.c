#include <stdio.h>
#define SIZE 100
int q[SIZE], front = 0, rear = -1;

void insert(int x)
{
    if (rear < SIZE - 1)
        q[++rear] = x;
}

void delete()
{
    if (front <= rear)
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

int main()
{
    int ch, val;
    while (1)
    {
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}
