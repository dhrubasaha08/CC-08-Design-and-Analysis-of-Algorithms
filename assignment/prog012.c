/*************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     12
Program Name:   Write a C program to sort all the data in a binary search tree either in ascending order or in
                descending order.
Date:           10/05/2022
**************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;

NODE *newNode();
NODE *insert();
void ascend();
void descend();

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

    printf("Binary search tree sorted in accending:\n");
    ascend(root);
    printf("\n");

    printf("Binary search tree sorted in decending:\n");
    descend(root);
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

void ascend(NODE *root)
{
    if (root != NULL)
    {
        ascend(root->left);
        printf("%d ", root->data);
        ascend(root->right);
    }
}

void descend(NODE *root)
{
    if (root != NULL)
    {
        descend(root->right);
        printf("%d ", root->data);
        descend(root->left);
    }
}

/*
Output:
Binary search tree sorted in accending:
10 20 30 40 50 60 70 80 90 100
Binary search tree sorted in decending:
100 90 80 70 60 50 40 30 20 10
*/