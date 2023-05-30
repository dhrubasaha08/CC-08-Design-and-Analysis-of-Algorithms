/**********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     9
Program Name:   Write a C program to create a binary search tree. Then implement the following: a) insert an
                element b) delete an element c) search an element and show the result accordingly.
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE *newNode();
NODE *insert();
void inorder();
NODE *search();
NODE *delete ();
NODE *minValue();

int main()
{
    int choice, data;
    NODE *root = NULL;

    while (1)
    {
        printf("1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            NODE *temp = search(root, data);
            if (temp == NULL)
            {
                printf("Data not found\n");
            }
            else
            {
                printf("Data found\n");
            }
            break;
        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("Data Deleted\n");
            break;
        case 4:
            printf("Display\n");
            inorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}

NODE *newNode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
    free(temp);
}

NODE *insert(NODE *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

NODE *search(NODE *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data == root->data)
    {
        return root;
    }
    else if (data < root->data)
    {
        return search(root->left, data);
    }
    else if (data > root->data)
    {
        return search(root->right, data);
    }
}

NODE *delete (NODE *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            NODE *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            NODE *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            NODE *temp = minValue(root->right);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
}

NODE *minValue(NODE *root)
{
    NODE *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
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