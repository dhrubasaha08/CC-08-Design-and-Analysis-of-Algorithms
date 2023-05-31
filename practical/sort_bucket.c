/**********************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     34
Program Name:   Write a C program to implement Bucket sort.
Date:           3/7/2022
**********************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void bucketSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before bucket sort\n");
    printArr(arr, n);

    bucketSort(arr, n);

    printf("After bucket sort\n");
    printArr(arr, n);
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

void bucketSort(int *arr, int n)
{
    int i, j, k, *bucket, max, min, range;

    max = arr[0];
    min = arr[0];

    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;
    bucket = (int *)malloc(sizeof(int) * range);

    for (i = 0; i < range; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
        bucket[arr[i] - min]++;

    k = 0;
    for (i = 0; i < range; i++)
    {
        for (j = 0; j < bucket[i]; j++)
            arr[k++] = i + min;
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

Enter the number of elements:
4
Enter the element 1:
3
Enter the element 2:
1
Enter the element 3:
2
Enter the element 4:
1
Before bucket sort
3 1 2 1
After bucket sort
1 1 2 3

*/