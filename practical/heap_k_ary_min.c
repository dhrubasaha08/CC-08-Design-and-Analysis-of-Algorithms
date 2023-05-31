/***********************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     23B
Program Name:   Write a C program to create a k-ary minheap.
Date:           13/06/2022
************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define K 3

int parent(int i);
int left(int i);
int right(int i);
void minheapify(int *a, int i, int n);
void buildminheap(int *a, int n);
void inputArr(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before k-ary minheapify(k=3):\n");
    printArr(arr, n);

    buildminheap(arr, n);

    printf("After k-ary minheapify(k=3):\n");
    printArr(arr, n);
}

int parent(int i)
{
    return (i - 1) / K;
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}

void minheapify(int *a, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int smallest;
    if (l < n && a[l] < a[i])
        smallest = l;
    else
        smallest = i;
    if (r < n && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        minheapify(a, smallest, n);
    }
}

void buildminheap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(a, i, n);
}

void inputArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:\n", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
Output:

Enter the number of elements in the array:5
Enter the element 1:
34
Enter the element 2:
10
Enter the element 3:
60
Enter the element 4:
45
Enter the element 5:
70
Before k-ary minheapify(k=3):
34 10 60 45 70
After k-ary minheapify(k=3):
10 34 60 45 70
*/