/*****************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     11
Program Name:   Write a C program to implement inorder, preorder and postorder traversals in a binary search tree.
Date:           10/05/2022
*****************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;

NODE *newNode();
NODE *insert();
void inorder();
void preorder();
void postorder();

void main()
{
    NODE *root = NULL;

    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("Inorder traversal of the constructed binary search tree:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal of the constructed binary search tree:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal of the constructed binary search tree:\n");
    postorder(root);
    printf("\n");
}

NODE *newNode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp; 
}

NODE *insert(NODE *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
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

void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/*
Output:
Inorder traversal of the constructed binary search tree:
10 20 30 40 50 60 70 80 90 100
Preorder traversal of the constructed binary search tree:
60 10 20 30 40 50 70 80 90 100
Postorder traversal of the constructed binary search tree:
50 40 30 20 10 100 90 80 70 60
*/