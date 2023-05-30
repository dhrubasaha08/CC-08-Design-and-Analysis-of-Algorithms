//subtract a matrix from another matrix using recursion
#include <stdio.h>
#include <stdlib.h>

int inputMAT();
int subtractMAT();
void outputMAT();

void main()
{
    int m, n, **a, **b, **c;

    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d%d", &m, &n);

    a = (int **)calloc(m, sizeof(int *));
    b = (int **)calloc(m, sizeof(int *));
    c = (int **)calloc(m, sizeof(int *));
    
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)calloc(n, sizeof(int));
        b[i] = (int *)calloc(n, sizeof(int));
        c[i] = (int *)calloc(n, sizeof(int));
    }

    printf("Enter the elements of the first matrix:\n");
    inputMAT(a, m, n);

    printf("Enter the elements of the second matrix:\n");
    inputMAT(b, m, n);

    subtractMAT(a, b, c, m, n);

    printf("The subtraction of the two matrices is:\n");
    outputMAT(c, m, n);

    for (int i = 0; i < m; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
}

int inputMAT(int **a, int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int subtractMAT(int **a, int **b, int **c, int m, int n)
{
    int i, j;
    if (m == 1 && n == 1)
    {
        c[0][0] = a[0][0] - b[0][0];
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
    }
}

void outputMAT(int **a, int m, int n)
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