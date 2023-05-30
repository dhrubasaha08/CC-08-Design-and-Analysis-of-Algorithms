/*********************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     6B
Program Name:   Write a C program to implement bubble sort using recursion method.
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int inputArr();
int sortArr();
void outputArr();

int i = 0;

void main()
{
    int n, *a, *b;

    printf("Enter the number of element in the array:\n");
    scanf("%d", &n);
    a = (int *)calloc(n, sizeof(int));
    b = (int *)calloc(n, sizeof(int));

    inputArr(a, n);

    printf("Before bubble sort:\n");
    outputArr(a, n);

    for (int j = n; j >= 1; j--)
    {
        i=0;
        sortArr(a, b, j);
    }
    printf("after bubble sort:\n");
    outputArr(b, n);
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

int sortArr(int *a, int *b, int n)
{
    int temp;
    if (n == 1)
        return 1;
    else
    {
        if (a[i] > a[i + 1])
        {
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }

        b[i] = a[i];
        b[i + 1] = a[i + 1];
        i++;
        return sortArr(a, b, (n - 1));
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