/******************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     26
Program Name:   Write a C program to implement parenthesization problem. (Matrix chain multiplication)
Date:           30/06/2022
******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrixChainOrder(int *p, int n);

void main()
{
    int n, *p;

    printf("Enter the number of matrices:");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));

    printf("Enter the dimensions of matrices:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("The minimum number of multiplications is %d\n", matrixChainOrder(p, n));

    free(p);
}

int matrixChainOrder(int *p, int n)
{
    int i, j, k, l, q, m[n][n];

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

/*
Output:

Enter the number of matrices:3
Enter the dimensions of matrices:10 20 5
The minimum number of multiplications is 1000
*/