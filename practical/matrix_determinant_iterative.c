/*****************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     7
Program Name:   Write a C program to find the determinant of a matrix by iterative approach.
Date:           07/05/2022
******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int **allocMem();
int inputMat();
int triangularMat();
int detMat();
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

int triangularMat(int **a, int n)
{
    int i, j, k, ratio;
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            printf("Error!\n");
            exit(0);
        }
        for (j = i + 1; j < n; j++)
        {
            ratio = a[j][i] / a[i][i];

            for (k = 0; k < n; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
}

int detMat(int **a, int n)
{
    int i, j, det = 1;
    for (i = 0; i < n; i++)
    {
        det = det * a[i][i];
    }
    return det;
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

/*
Output:
Enter the number of row/column of the matrix (nxn):
3
Enter the elements of the matrix:
Element 1, 1:
3
Element 1, 2:
1
Element 1, 3:
1
Element 2, 1:
0
Element 2, 2:
2
Element 2, 3:
5
Element 3, 1:
0
Element 3, 2:
0
Element 3, 3:
4
Matrix:
3       1       1
0       2       5
0       0       4
The determinant of matrix = 24
*/