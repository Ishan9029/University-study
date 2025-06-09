#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node *insert(struct Node *root, int val)
{
    if (!root)
        return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (!root || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

struct Node *findMin(struct Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

struct Node *findMax(struct Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

struct Node *delete(struct Node *root, int key)
{
    if (!root)
        return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    int ch, val;
    while (1)
    {
        printf("\n1.Insert 2.Search 3.Min 4.Max 5.Delete 6.Exit\nChoice: ");
        scanf("%d", &ch);
        if (ch == 6)
            break;
        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        case 2:
            printf("Enter key: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("Found\n");
            else
                printf("Not Found\n");
            break;
        case 3:
            if (root)
                printf("Min: %d\n", findMin(root)->data);
            break;
        case 4:
            if (root)
                printf("Max: %d\n", findMax(root)->data);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            root = delete(root, val);
            break;
        }
    }
    return 0;
}
