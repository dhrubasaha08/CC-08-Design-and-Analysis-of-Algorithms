/**********************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     6
Program Name:   Write a C program to multiply two matrices by recursive approach.
Date:           06/05/2022
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

        multiplyMat(a, b, c, 0, m, 0, n, 0, m, 0, n);

        printf("The product of the two matrices:\n");
        outputMat(c, m, n);

        free(a);
        free(b);
        free(c);
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

int multiplyMat(int **a, int **b, int **c, int ars, int are, int acs, int ace, int brs, int bre, int bcs, int bce)
{
    if (are - ars == 1)
    {
        c[ars][bcs] += a[ars][acs] * b[acs][bcs];
    }
    else
    {
        int arm = (ars + are) / 2;
        int acm = (acs + ace) / 2;
        int brm = (brs + bre) / 2;
        int bcm = (bcs + bce) / 2;
        multiplyMat(a, b, c, ars, arm, acs, acm, brs, brm, bcs, bcm);
        multiplyMat(a, b, c, ars, arm, acm, ace, brm, bre, bcs, bcm);
        multiplyMat(a, b, c, ars, arm, acs, acm, brs, brm, bcm, bce);
        multiplyMat(a, b, c, ars, arm, acm, ace, brm, bre, bcm, bce);
        multiplyMat(a, b, c, arm, are, acs, acm, brs, brm, bcs, bcm);
        multiplyMat(a, b, c, arm, are, acm, ace, brm, bre, bcs, bcm);
        multiplyMat(a, b, c, arm, are, acs, acm, brs, brm, bcm, bce);
        multiplyMat(a, b, c, arm, are, acm, ace, brm, bre, bcm, bce);
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