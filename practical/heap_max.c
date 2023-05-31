/******************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     12
Program Name:   Write a C program to implement max heap
*******************************************************/

// implement max heap in c

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct node *left, *right;
} NODE;

NODE *creteNode();
NODE *insert();
void inorder();
NODE *deleteMax();
NODE *delete ();
NODE *maxValue();
NODE *maxHeapify();
NODE *buildMaxHeap();
NODE *heapSort();

NODE *root = NULL;

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
            root = delete (root, data);
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
    NODE *temp = (NODE *)malloc(sizeof(NODE));
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

NODE *deleteMax()
{
    NODE *temp = root;
    if (root->right == NULL)
    {
        root = root->left;
        free(temp);
        return root;
    }
    else
    {
        root->right = deleteMax(root->right);
    }
    return root;
}

NODE *delete (NODE *root, int data)
{
    if (root == NULL)
        return NULL;
    if (data < root->data)
        root->left = delete (root->left, data);
    else if (data > root->data)
        root->right = delete (root->right, data);
    else
    {
        if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            NODE *temp = maxValue(root->left);
            root->data = temp->data;
            root->left = delete (root->left, temp->data);
        }
    }
    return root;
}

NODE *maxValue(NODE *root)
{
    if (root->right == NULL)
        return root;
    else
        return maxValue(root->right);
}

NODE *maxHeapify(NODE *root)
{
    if (root->left == NULL && root->right == NULL)
        return root;
    else
    {
        if (root->left != NULL)
            root->left = maxHeapify(root->left);
        if (root->right != NULL)
            root->right = maxHeapify(root->right);
        if (root->left != NULL && root->right != NULL)
        {
            if (root->left->data > root->right->data)
                root = root->left;
            else
                root = root->right;
        }
    }
}

NODE *buildMaxHeap(NODE *root)
{
    if (root == NULL)
        return NULL;
    if (root->left != NULL)
        root->left = buildMaxHeap(root->left);
    if (root->right != NULL)
        root->right = buildMaxHeap(root->right);
    root = maxHeapify(root);
    return root;
}

NODE *heapSort(NODE *root)
{
    root = buildMaxHeap(root);
    while (root != NULL)
    {
        NODE *temp = root;
        root = deleteMax(root);
        printf("%d ", temp->data);
    }
    return root;
}