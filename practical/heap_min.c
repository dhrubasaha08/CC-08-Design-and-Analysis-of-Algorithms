/******************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     11
Program Name:   Write a C program to implement min heap
*******************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct node *left, *right;
}NODE;

NODE *creteNode();
NODE *insert();
void inorder();
NODE *deleteMin();
NODE *delete();
NODE *minValue();

int main()
{
    NODE *root = NULL;
    int data, choice;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data:\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data:\n");
            scanf("%d", &data);
            root = delete(root, data);
            break;
        case 3:
            printf("Display\n");
            inorder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

NODE *createNode(int data)
{
    NODE *temp = (struct node *)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

NODE *insert(NODE *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

NODE *deleteMin(NODE *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root->right;
    root->left = deleteMin(root->left);
    return root;
}

NODE *delete(NODE *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else
    {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;
        else
        {
            NODE *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = deleteMin(root->right);
        }
    }
    return root;
}