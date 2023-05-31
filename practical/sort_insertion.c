/************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     19
Program Name:   Write a C program to implement insertion sort. Use dynamic memory allocation and subfunction.
Date:           09/06/2022
*************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void insertionSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    
    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before insertion sort\n");
    printArr(arr, n);

    insertionSort(arr, n);

    printf("After insertion sort\n");
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

void insertionSort(int *arr, int n)
{
    int i, j, temp;

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
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
Enter the number of elements:
5
Enter the element 1:
78
Enter the element 2:
56
Enter the element 3:
45
Enter the element 4:
565
Enter the element 5:
74
Before insertion sort
Array:
78 56 45 565 74
After insertion sort
Array:
45 56 74 78 565
*/