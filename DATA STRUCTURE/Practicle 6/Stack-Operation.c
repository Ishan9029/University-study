#include <stdio.h>
#define SIZE 100
int stack[SIZE], top = -1;

void push(int x)
{
    if (top < SIZE - 1)
        stack[++top] = x;
}

void pop()
{
    if (top >= 0)
        top--;
}

void display()
{
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int ch, val;
    while (1)
    {
        printf("1.Push \n2.Pop \n3.Display \n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
}
