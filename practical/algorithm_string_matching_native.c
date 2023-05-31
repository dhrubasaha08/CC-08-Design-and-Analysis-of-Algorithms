/*****************************************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     29
Program Name:   Write a C program to implement Naive String Matching algorithm.
Date:           3/7/2022
******************************************************************************/

#include <stdio.h>
#include <string.h>

void main()
{
    char str1[100], str2[100];
    int i, j, k, l, m, n, count = 0;

    printf("Enter the string 1: ");
    scanf("%s", str1);

    printf("Enter the string 2: ");
    scanf("%s", str2);

    n = strlen(str1);
    m = strlen(str2);
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (str1[i + j] != str2[j])
            {
                break;
            }
        }
        if (j == m)
        {
            count++;
        }
    }
    printf("Number of times string 2 occurs in string 1: %d\n", count);
}

/*
Output:

Enter the string 1: wwwwwww
Enter the string 2: w
Number of times string 2 occurs in string 1: 7

*/