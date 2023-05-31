/************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     20
Program Name:   Write a C program to implement selection sort. Use dynamic memory allocation and subfunction.
Date:           09/06/2022
*************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void selectionSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before selection sort\n");
    printArr(arr, n);

    selectionSort(arr, n);

    printf("After selection sort\n");
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

void selectionSort(int *arr, int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
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
96
Enter the element 2:
564
Enter the element 3:
53
Enter the element 4:
642
Enter the element 5:
100
Before selection sort
Array:
96 564 53 642 100
After selection sort
Array:
53 96 100 564 642
*/