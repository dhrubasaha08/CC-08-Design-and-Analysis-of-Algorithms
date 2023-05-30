/**********************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     3
Program Name:   Write a C program to multiply two matrices by iterative approach.
Date:           05/05/2022
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int **allocMem();
int inputMat();
int multiplyMat();
void outputMat();

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

/*
Enter the number of rows and columns of matrices:
2
2
Enter the elements of first matrix:
Element 1, 1:
2
Element 1, 2:
2
Element 2, 1:
2
Element 2, 2:
2
Enter the elements of second matrix:
Element 1, 1:
2
Element 1, 2:
2
Element 2, 1:
2
Element 2, 2:
2
Matrix A:
2 2 
2 2 
Matrix B:
2 2 
2 2 
The product of the two matrices:
8 8 
8 8 
*/