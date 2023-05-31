/********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     21
Program Name:   Write a C program to implement merge sort. Use dynamic memory allocation and subfunction.
Date:           11/06/2022
*********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int n);
void printArr(int *arr, int n);
void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);

void main()
{
    int n, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    inputArr(arr, n);

    printf("Before merge sort:\n");
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("After merge sort:\n");
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

void merge(int *arr, int l, int m, int r)
{
    int i, j, k, n1, n2;
    int *temp = (int *)malloc((r - l + 1) * sizeof(int));

    n1 = m - l + 1;
    n2 = r - m;

    for (i = 0; i < n1; i++)
        temp[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        temp[n1 + j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (temp[i] <= temp[n1 + j])
        {
            arr[k] = temp[i];
            i++;
        }
        else
        {
            arr[k] = temp[n1 + j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = temp[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = temp[n1 + j];
        j++;
        k++;
    }

    free(temp);
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
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
Enter the number of elements: 7
Enter the element 1:
43
Enter the element 2:
78
Enter the element 3:
12
Enter the element 4:
67
Enter the element 5:
89
Enter the element 6:
54
Enter the element 7:
33
Before merge sort:
Array:
43 78 12 67 89 54 33
After merge sort:
Array:
12 33 43 54 67 78 89
*/