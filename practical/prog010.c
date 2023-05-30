/****************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     10
Program Name:   Write a C program to gcd of two number recursion
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

int gcd();

void main()
{
    int a, b;
    printf("Enter the two numbers:\n");
    scanf("%d%d", &a, &b);
    printf("The gcd of %d and %d = %d\n", a, b, gcd(a, b));
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}