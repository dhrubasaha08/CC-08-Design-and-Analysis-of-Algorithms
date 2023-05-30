/**********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     10
Program Name:   Write a C program to create a binary search tree. Then implement the following: a) insert an
                element b) delete an element c) search an element and show the result accordingly.
Date:           09/05/2022
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
NODE *search();
NODE *delete ();
NODE *minValue();
void inorder();

int main()
{

    NODE *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);

    printf("Inorder traversal of the constructed tree:\n");
    inorder(root);
    printf("\n");

    printf("Searching for the data 100:\n");

    NODE *temp = search(root, 100);
    if (temp == NULL)
    {
        printf("Data not found\n");
    }
    else
    {
        printf("Data found\n");
    }

    printf("Deleting the data 100:\n");
    root = delete (root, 100);
    printf("Inorder traversal of the constructed tree:\n");
    inorder(root);
    printf("\n");

    return 0;
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

/*
Output:
Inorder traversal of the constructed tree:
10 20 30 40 50 60 70 80 90 100
Searching for the data 100:
Data found
Deleting the data 100:
Inorder traversal of the constructed tree:
10 20 30 40 50 60 70 80 90
*/