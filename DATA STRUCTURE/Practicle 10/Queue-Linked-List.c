#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void insert(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    if (!rear)
        front = rear = n;
    else
    {
        rear->next = n;
        rear = n;
    }
}

void delete()
{
    if (front)
    {
        struct Node *t = front;
        front = front->next;
        if (!front)
            rear = NULL;
        free(t);
    }
}

void display()
{
    struct Node *t = front;
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
