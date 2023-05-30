/**********************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     3B
Program Name:   Write a C program to multiply two matrices by recursive approach.
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
    static int i = 0, j = 0, k = 0;

    if (i >= m)
        return 0;

    if (j < n)
    {
        if (k < n)
        {
            c[i][j] += a[i][k] * b[k][j];
            k++;
            multiplyMat(a, b, c, m, n);
        }
        k = 0;
        j++;
        multiplyMat(a, b, c, m, n);
    }
    
    j = 0;
    i++;
    multiplyMat(a, b, c, m, n);
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
