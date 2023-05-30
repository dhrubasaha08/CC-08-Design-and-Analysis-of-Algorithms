#include <stdio.h>
#include <stdlib.h>

int inputMatrix();
int multiplyMatrix();
int outputMatrix();

void main()
{
    int m, n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);

    int a[m][n], b[n][m], c[m][m];

    printf("Enter the 1st matrix-\n");
    inputMatrix(a, m, n);printf("\n");

    printf("Enter the 2nd matrix-\n");
    inputMatrix(b, n, m);

    multiplyMatrix(a,b,m,n);

    outputMatrix(c,m,n);
}

int inputMatrix(int m, int n, int a[m][n])
{
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            printf("Enter element:");
    scanf("%d", &a[i][j]);
}

int multiplyMatrix(int m, int n,int a[m][n], int b[n][m])
{
    int c[m][n],i,j,k;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
    outputMatrix(c, m, n);
}

int outputMatrix(int m, int n,int c[m][n])
{
    int i, j;
    printf("The product of the two matrices is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
}