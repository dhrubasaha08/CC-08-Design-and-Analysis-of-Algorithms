/**********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     25
Program Name:   Write a C program to sort (ascending or descending) a list of elements through a k-ary heap.
Date:           30/06/2022
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define K 3

int parent(int i);
int left(int i);
int right(int i);
void maxheapify(int *a, int i, int n);
void buildmaxheap(int *a, int n);
void heapsort(int *a, int n);
void inputArr(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before sorting:\n");
    printArr(arr, n);

    buildmaxheap(arr, n);
    heapsort(arr, n);

    printf("After sorting:\n");
    printArr(arr, n);

    free(arr);
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

void heapsort(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        maxheapify(a, 0, i);
    }
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
23
Enter the element 2:
44
Enter the element 3:
7
Enter the element 4:
231
Enter the element 5:
4
Before sorting:
23 44 7 231 4
After sorting:
4 7 23 44 231
*/