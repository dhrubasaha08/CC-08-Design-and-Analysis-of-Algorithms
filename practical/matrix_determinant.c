/******************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     4A
Program Name:   Write a C program to get determinant two matrices iteratively.
Date:           14/03/2022
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int inputMat();
int determinantMat();
void outputMat();

void main()
{
    int m, n, i, **a, **b;

step1:
    printf("Enter the number of rows and columns of matrices:\n");
    scanf("%d%d", &m, &n);

    if (m != n)
    {
        printf("\nThe matrix must be a square matrix.\n");
        goto step1;
    }

    a = (int **)calloc(m, sizeof(int *));
    b = (int **)calloc(m, sizeof(int *));

    for (i = 0; i < m; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
        b[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    inputMat(a, m, n);

    printf("The determinant of the matrix: %d\n", determinantMat(a, b, m, n));

    for (int i = 0; i < m; i++)
    {
        free(a[i]);
        free(b[i]);
    }
}

int inputMat(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Element %d, %d:\n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

int det(int **a, int m, int n)
{
    int i, j;
    if (m != n)
    {
        printf("Order is not same !\n");
        exit(1);
    }
    else if (m == 1)
        return a[0][0];
    else if (m == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else
        int 
}