/*********************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     24A
Program Name:   Write a C program to sort (ascending) a list of elements through a binary heap.
Date:           14/06/2022
**********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void maxHeapify(int *arr, int n, int i);
void buildMaxHeap(int *arr, int n);
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

    printf("After sorting in ascending order\n");

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

void maxHeapify(int *arr, int n, int i)
{
    int largest, left, right;

    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < n && arr[left] > arr[i])
    {
        largest = left;
    }
    else
    {
        largest = i;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int *arr, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int *arr, int n)
{
    buildMaxHeap(arr, n);

    int i;

    for (i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, i, 0);
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
46
32
13
45
67
89
73
49
6
5
Before sorting
46 32 13 45 67 89 73 49 6 5
After sorting in ascending order
5 6 13 32 45 46 49 67 73 89
*/