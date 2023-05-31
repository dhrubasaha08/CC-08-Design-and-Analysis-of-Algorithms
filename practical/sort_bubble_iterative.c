/*********************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     6
Program Name:   Write a C program to implement bubble sort using iterative method.
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int inputArr();
int sortArr();
void outputArr();

void main()
{
    int n, *a;

    printf("Enter the number of element in the array:\n");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));

    inputArr(a, n);

    printf("Before bubble sort:\n");
    outputArr(a, n);

    sortArr(a, n);
    
    printf("after bubble sort:\n");
    outputArr(a, n);
}

int inputArr(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the element %d:\n", i + 1);
        scanf("%d", &a[i]);
    }
}

int sortArr(int *a, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void outputArr(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}