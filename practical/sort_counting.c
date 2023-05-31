/************************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     32
Program Name:   Write a C program to implement Counting sort.
Date:           3/7/2022
*************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void countingSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before counting sort\n");
    printArr(arr, n);

    countingSort(arr, n);

    printf("After counting sort\n");
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

void countingSort(int *arr, int n)
{
    int i, max = arr[0], min = arr[0];
    int *count, *output;

    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    count = (int *)malloc(sizeof(int) * (max - min + 1));
    output = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < (max - min + 1); i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i] - min]++;

    for (i = 1; i < (max - min + 1); i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
        output[count[arr[i] - min] - 1] = arr[i];

    for (i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
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

Enter the number of elements:
4
Enter the element 1:
32
Enter the element 2:
190
Enter the element 3:
50
Enter the element 4:
1
Before counting sort
32 190 50 1 
After counting sort
1 32 50 190 

*/