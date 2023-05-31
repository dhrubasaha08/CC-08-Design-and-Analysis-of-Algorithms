/*********************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     24B
Program Name:   Write a C program to sort (decending) a list of elements through a binary heap.
Date:           14/06/2022
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void minHeapify(int *arr, int n, int i);
void buildMinHeap(int *arr, int n);
void heapSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter number of elements:");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before sorting\n");

    printArr(arr, n);

    heapSort(arr, n);

    printf("After sorting in decending order\n");

    printArr(arr, n);

    free(arr);
}

void inputArr(int *arr, int n)
{
    int i;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void minHeapify(int *arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < n && arr[left] < arr[i])
    {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int *arr, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

void heapSort(int *arr, int n)
{
    buildMinHeap(arr, n);

    int i;

    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        minHeapify(arr, i, 0);
    }
}

void printArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

/*
Output:

Enter number of elements:10
Enter elements:
23
45
22
56
78
91
27
5
1
10
Before sorting
23 45 22 56 78 91 27 5 1 10
After sorting in decending order
91 78 56 45 27 23 22 10 5 1
*/