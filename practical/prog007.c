/****************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     7
Program Name:   Write a C program to sum of N natural number using  recursion
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int sum();

void main()
{
    int n;
    printf("Enter the number of natural numbers:\n");
    scanf("%d", &n);
    printf("The sum of natural numbers = %d\n", sum(n));
}

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}