#include <stdio.h>
#include <stdlib.h>

int inputMat();
int addMat();
void outputMat();

void main()
{
    int m, n, i, j, **a, **b, **c;

    printf("Enter the number of rows and columns in the matrix:\n");
    scanf("%d%d", &m, &n);

    a = (int **)calloc(m, sizeof(int *));
    b = (int **)calloc(m, sizeof(int *));
    c = (int **)calloc(m, sizeof(int *));

    for (i = 0; i < n; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
        b[i] = (int *)calloc(n, sizeof(int));
        c[i] = (int *)calloc(n, sizeof(int));
    }

    inputMat(a, m, n);
    inputMat(b, m, n);

    printf("Matrix A:\n");
    outputMat(a, m, n);
    printf("Matrix B:\n");
    outputMat(b, m, n);

    addMat(a, b, c, m, n);

    printf("Matrix C:\n");
    outputMat(c, m, n);
}

int inputMat(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter the element %d, %d:\n", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

int addMat(int **a, int **b, int **c, int m, int n)
{
    int i, j;
    if (m == 1)
    {
        for (i = 0; i < n; i++)
        {
            c[0][i] = a[0][i] + b[0][i];
        }
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        addMat(a, b, c, m - 1, n);
    }
}

void outputMat(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
