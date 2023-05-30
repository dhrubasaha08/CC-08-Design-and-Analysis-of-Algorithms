/**********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     9
Program Name:   Write a C program to implement inorder, preorder and postorder traversals in a binary tree.
Date:           08/05/2022
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}NODE;

NODE *newNode();
void inorder();
void preorder();
void postorder();

void main()
{
    NODE *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");
}

NODE *newNode(int data)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
    free (temp);
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
Inorder traversal:
4 2 5 1 6 3 7 
Preorder traversal:
1 2 4 5 3 6 7 
Postorder traversal:
4 5 2 6 7 3 1
*/