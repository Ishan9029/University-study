#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertBegin(int x)
{
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x)
{
    struct Node *n = malloc(sizeof(struct Node)), *t = head;
    n->data = x;
    n->next = NULL;
    if (!head)
        head = n;
    else
    {
        while (t->next)
            t = t->next;
        t->next = n;
    }
}

void insertAfter(int after, int x)
{
    struct Node *t = head;
    while (t && t->data != after)
        t = t->next;
    if (t)
    {
        struct Node *n = malloc(sizeof(struct Node));
        n->data = x;
        n->next = t->next;
        t->next = n;
    }
}

void deleteFirst()
{
    if (head)
    {
        struct Node *t = head;
        head = head->next;
        free(t);
    }
}

void deleteLast()
{
    if (!head)
        return;
    if (!head->next)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *t = head, *prev;
    while (t->next)
    {
        prev = t;
        t = t->next;
    }
    prev->next = NULL;
    free(t);
}

void deleteAfter(int after)
{
    struct Node *t = head;
    while (t && t->data != after)
        t = t->next;
    if (t && t->next)
    {
        struct Node *temp = t->next;
        t->next = temp->next;
        free(temp);
    }
}

void deleteAtPos(int pos)
{
    if (pos == 0 && head)
    {
        deleteFirst();
        return;
    }
    struct Node *t = head, *prev = NULL;
    for (int i = 0; i < pos && t; i++)
    {
        prev = t;
        t = t->next;
    }
    if (t)
    {
        prev->next = t->next;
        free(t);
    }
}

void display()
{
    struct Node *t = head;
    while (t)
    {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch, val, pos;
    while (1)
    {
        printf("\n 1.Insert Begin\n 2.Insert End\n 3.Insert After\n 4.Delete First\n 5.Delete Last\n 6.Delete After\n 7.Delete At Pos\n 8.Display\n 9.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &val);
            insertBegin(val);
            break;
        case 2:
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 3:
            scanf("%d%d", &pos, &val);
            insertAfter(pos, val);
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteLast();
            break;
        case 6:
            scanf("%d", &pos);
            deleteAfter(pos);
            break;
        case 7:
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        case 8:
            display();
            break;
        case 9:
            return 0;
        }
    }
}
