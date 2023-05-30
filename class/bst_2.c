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
    int n, i, temp;

    printf("Enter no of data in the tree to be inserted:");
    scanf("%d", &n);

    for (i = 0; i <= n - 1; i++)
    {
        printf("Data %d:", i + 1);
        scanf("%d", &temp);
        root = insert(root, temp);
    }

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
    free(temp);
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