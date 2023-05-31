/************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     22B
Program Name:   Write a C program to create a binary minheap.
Date:           11/06/2022
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void minHeapify(int *arr, int n, int i);
void buildMinHeap(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before min heapify:\n");
    printArr(arr, n);

    buildMinHeap(arr, n);

    printf("After min heapify:\n");
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

void minHeapify(int *arr, int n, int i)
{
    int l, r, smallest, temp;

    l = 2 * i + 1;
    r = 2 * i + 2;
    smallest = i;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

void buildMinHeap(int *arr, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
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
21
Enter the element 2:
23
Enter the element 3:
56
Enter the element 4:
71
Enter the element 5:
2
Before min heapify:
21 23 56 71 2 
After min heapify:
2 21 56 71 23
*/