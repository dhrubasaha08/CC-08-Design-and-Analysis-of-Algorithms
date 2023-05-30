/******************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     9
Program Name:   Write a C program to implement Binary Search Tree(Inorder, Preorder, Postorder).
Date:           28/03/2022
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int element;
    struct node *left;
    struct node *right;
};

void inorderTraversal();
void preorderTraversal();
void postorderTraversal();
struct node *createNode();
struct node *insertLeft();
struct node *insertRight();

int main()
{
    struct node *root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Preorder Traversal\n");
    preorderTraversal(root);
    printf("\nInorder Traversal\n");
    inorderTraversal(root);
    printf("\nPostorder Traversal\n");
    postorderTraversal(root);
    printf("\n");
}

void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->element);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->element);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->element);
}

struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->element = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}