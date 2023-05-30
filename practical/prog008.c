/************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     8
Program Name:   Write a C program to multiply first N natural number using recursion.
*************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int multiply();

void main()
{
    int n;
    printf("Enter the N : ");
    scanf("%d", &n);
    printf("The multiplication of first %d natural numbers = %d\n", n, multiply(n));
}

int multiply(int n)
{
    if (n == 1)
        return 1;
    else
        return n * multiply(n - 1);
}