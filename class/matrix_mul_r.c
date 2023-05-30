/******************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     3B
Program Name:   Write a C program to multiply two matrices recursively.
Date:           05/04/2022
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int **allocMem();
int inputMat();
int multiplyMat();
void outputMat();
int smmr();

void main()
{
    int m, n, **a, **b, **c;

    printf("Enter the number of rows and columns of matrices:\n");
    scanf("%d%d", &m, &n);

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

    multiplyMat(a, b, c, m, n);

    printf("The product of the two matrices:\n");
    outputMat(c, m, n);

    free(a);
    free(b);
    free(c);
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

int multiplyMat(int **a, int **b, int **c, int m, int n)
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
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

int multiply(int ars, int acs, int brs, int bcs, int **a, int **b, int **c)
{
    if (are - ars == 1)
        C[ars][acs] = A[ars][acs] * B[ars][acs];
    else   
    {
        multiply(ars, acs, ars + are / 2, acs + acs / 2, A, B, C);
        multiply(ars + are / 2, acs, ars + are / 2, acs + acs / 2, A, B, C);
        multiply(ars, acs + acs / 2, ars + are / 2, acs + acs / 2, A, B, C);
        multiply(ars + are / 2, acs + acs / 2, ars + are / 2, acs + acs / 2, A, B, C);

        for (i = ars; i < ars + are / 2; i++)
        {
            for (j = acs; j < acs + acs / 2; j++)
            {
                C[i][j] = C[i][j] + C[i][j + acs / 2] + C[i + ars / 2][j] + C[i + ars / 2][j + acs / 2];
            }
        }
    }
}
