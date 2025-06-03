#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop()
{
    if (top)
    {
        struct Node *t = top;
        top = top->next;
        free(t);
    }
}

void display()
{
    struct Node *t = top;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
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
