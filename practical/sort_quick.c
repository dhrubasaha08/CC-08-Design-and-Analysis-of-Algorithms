/******************************************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     31
Program Name:   Write a C program to sort a list of numbers by using quick sort.
Date:           3/7/2022
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before quick sort\n");
    printArr(arr, n);

    quickSort(arr, 0, n - 1);

    printf("After quick sort\n");
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(int *arr, int n)
{
    int i;

    printf("Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
Output:

Enter the number of elements:
5
Enter the element 1:
23
Enter the element 2:
10
Enter the element 3:
6
Enter the element 4:
7
Enter the element 5:
3
Before quick sort
Array:
23 10 6 7 3
After quick sort
Array:
3 6 7 10 23

*/