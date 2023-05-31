/*********************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     33
Program Name:   Write a C program to implement Radix sort.
Date:           3/7/2022
**********************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void radixSort(int *arr, int n);
void printArr(int *arr, int n);

void main()
{
    int n, *arr;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    inputArr(arr, n);

    printf("Before radix sort\n");
    printArr(arr, n);

    radixSort(arr, n);

    printf("After radix sort\n");
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

void radixSort(int *arr, int n)
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

    for (i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    for (i = 1; i < max - min + 1; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

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
6
Enter the element 1:
34
Enter the element 2:
20 
Enter the element 3:
56
Enter the element 4:
1
Enter the element 5:
5
Enter the element 6:
78
Before radix sort
34 20 56 1 5 78 
After radix sort
1 5 20 34 56 78 

*/