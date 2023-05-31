/******************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     2A
Program Name:   Write a robust C program to find all prime numbers upto a N.
Date:           14/03/2022
*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int input();
int prime();
void output();

void main()
{
    int n;

    input(n);
    prime(n);
    output(n);
}

int input(int n)
{
    printf("Enter N:\n");
    scanf("%d",&n);
}

int prime(int n)
{
    int *a, i, j, k, s = 1, p;

    a = (int *)calloc(n / 2, sizeof(int));

    a[0] = 2;
    a[1] = 3;

    for (j = 5; j <= n; j += 2)
    {
        p = (int)(sqrt(j));
        i = 1;
        for (k = a[i]; k <= p; k = a[i])
        {
            i++;
            if (j % k == 0)
                break;
        }
        if (k > p)
        {
            i++;
            s++;
            a[s] = j;
        }
    }
}

void output(int *a)
{
    int i;
    for (i = 0; a[i] != 0; i++)
        printf("Prime[%d]=%d\n", i + 1, a[i]);
}

