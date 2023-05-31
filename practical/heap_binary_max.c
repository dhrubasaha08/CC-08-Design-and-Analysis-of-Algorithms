/************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     22A
Program Name:   Write a C program to create a binary maxheap.
Date:           11/06/2022
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void maxHeapify(int *arr, int n, int i);
void buildMaxHeap(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before max heapify:\n");
    printArr(arr, n);

    buildMaxHeap(arr, n);

    printf("After max heapify:\n");
    printArr(arr, n);

    free(arr);
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

void maxHeapify(int *arr, int n, int i)
{
    int largest, l, r;

    l = 2 * i + 1;
    r = 2 * i + 2;

    if (l < n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r < n && arr[r] > arr[largest])
        largest = r;

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
        maxHeapify(arr, n, i);
}

void printArr(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*
Enter the number of elements: 5
Enter the element 1:
34
Enter the element 2:
21
Enter the element 3:
10
Enter the element 4:
6
Enter the element 5:
43
Before max heapify:
34 21 10 6 43 
After max heapify:
43 34 10 6 21 
*/