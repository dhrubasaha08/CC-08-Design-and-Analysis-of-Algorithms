/******************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     5
Program Name:   Write a C program to subtract one matrix from another by recursive approach.
Date:           06/05/2022
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int **allocMem();
int inputMat();
int subtractMat();
void outputMat();

void main()
{
    int m, n, **a, **b, **c;

    printf("Enter the number of rows and columns of matrices:\n");
    scanf("%d%d", &m, &n);

    if (m % 2 == 0 && n % 2 == 0)
    {
        a = allocMem(m, n);
        b = allocMem(m, n);
        c = allocMem(m, n);

        printf("Enter the elements of first matrix:\n");
        inputMat(a, m, n);

        printf("Enter the elements of second matrix:\n");
        inputMat(b, m, n);

        printf("Matrix A:\n");
        outputMat(a, m, n);

        printf("Matrix B:\n");
        outputMat(b, m, n);

        subtractMat(a, b, c, 0, m, 0, n);

        printf("The subtraction of the two matrices:\n");
        outputMat(c, m, n);
    }
    else
    {
        printf("The number of rows and columns of matrices should be even for divide and conquer method.\n");
    }
}

int **allocMem(int m, int n)
{
    int **x, i;
    x = (int **)calloc(m, sizeof(int *));
    for (i = 0; i < m; i++)
    {
        x[i] = (int *)calloc(n, sizeof(int));
    }
    return x;
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

int subtractMat(int **a, int **b, int **c, int rs, int re, int cs, int ce)
{
    if (re - rs == 1)
        c[rs][cs] = a[rs][cs] - b[rs][cs];
    else
    {
        int rm = (rs + re) / 2;
        int cm = (cs + ce) / 2;
        subtractMat(a, b, c, rs, rm, cs, cm);
        subtractMat(a, b, c, rs, rm, cm, ce);
        subtractMat(a, b, c, rm, re, cs, cm);
        subtractMat(a, b, c, rm, re, cm, ce);
    }
}

void outputMat(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/*
Output:
Enter the number of rows and columns of matrices:
2 2
Enter the elements of first matrix:
Element 1, 1:
40
Element 1, 2:
40
Element 2, 1:
40
Element 2, 2:
40
Enter the elements of second matrix:
Element 1, 1:
10
Element 1, 2:
20
Element 2, 1:
10
Element 2, 2:
20
Matrix A:
40 40
40 40
Matrix B:
10 20
10 20
The subtraction of the two matrices:
30 20
30 20
*/