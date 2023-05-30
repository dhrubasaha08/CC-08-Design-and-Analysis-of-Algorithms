#include <stdio.h>
#include <stdlib.h>

void main()
{
    int m, n, i, j, row, col;
    printf("Enter the row and column of the matrix:");
    scanf("%d%d", &m, &n);

    printf("Enter the elements of the first matrix:");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element:");
            scanf("%d", &b[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element:");
            scanf("%d", &b[i][j]);
        }
    }
    printf("The multiplication  of the two matrices is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] * b[i][j];
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

}