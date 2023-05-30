/******************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     4B
Program Name:   Write a C program to find the determinant of a matrix by recursive approach.
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int **allocMem();
int inputMat();
int detMat();
int cofac();
void outputMat();

void main()
{
    int n, **a;

    printf("Enter the number of row/column of the matrix (nxn):\n");
    scanf("%d", &n);

    a = allocMem(n);

    printf("Enter the elements of the matrix:\n");
    inputMat(a, n);

    printf("Matrix:\n");
    outputMat(a, n);

    printf("The determinant of matrix = %d\n", detMat(a, n));

    free(a);
}

int **allocMem(int n)
{
    int **x, i;
    x = (int **)calloc(n, sizeof(int *));
    for (i = 0; i < n; i++)
    {
        x[i] = (int *)calloc(n, sizeof(int));
    }
    return x;
}

int inputMat(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Element %d, %d:\n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

int detMat(int **a, int n)
{
    int i, **b, det = 0, sign = 1;
    if (n == 1)
        return a[0][0];
    b = allocMem(n);
    for (i = 0; i < n; i++)
    {
        cofac(a, b, 0, i, n);
        det += sign * a[0][i] * detMat(b, n - 1);
        sign *= -1;
    }
    return det;
    free(b);
}

int cofac(int **a, int **b, int p, int q, int n)
{
    int i = 0, j = 0, row, col;
    for (row = 0; row < n; row++)
    {
        for (col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                b[i][j++] = a[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void outputMat(int **a, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}