/***********************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     23A
Program Name:   Write a C program to create a k-ary maxheap.
Date:           13/06/2022
***********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define K 3

int parent(int i);
int left(int i);
int right(int i);
void maxheapify(int *a, int i, int n);
void buildmaxheap(int *a, int n);
void inputArr(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before k-ary maxheapify(k=3):\n");
    printArr(arr, n);

    buildmaxheap(arr, n);

    printf("After k-ary maxheapify(k=3):\n");
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

void maxheapify(int *a, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < n && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        maxheapify(a, largest, n);
    }
}

void buildmaxheap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxheapify(a, i, n);
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

Enter the number of elements:5
Enter the element 1:
10
Enter the element 2:
4
Enter the element 3:
23
Enter the element 4:
56
Enter the element 5:
31
Before k-ary maxheapify(k=3):
10 4 23 56 31
After k-ary maxheapify(k=3):
56 31 23 4 10
*/