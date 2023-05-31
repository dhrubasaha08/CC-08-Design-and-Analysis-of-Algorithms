/****************************************************************************
Roll No:        B.Sc(Sem-IV)-04
Program No:     30
Program Name:   Write a C program to implement KMP String Matching algorithm.
Date:           3/7/2022
****************************************************************************/

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

    int lps[m];
    lps[0] = 0;

    k = 0;
    j = 1;

    while (j < m)
    {
        if (str2[j] == str2[k])
        {
            k++;
            lps[j] = k;
            j++;
        }
        else
        {
            if (k != 0)
            {
                k = lps[k - 1];
            }
            else
            {
                lps[j] = 0;
                j++;
            }
        }
    }

    k = 0;
    j = 0;

    while (j < n)
    {
        if (str1[j] == str2[k])
        {
            j++;
            k++;
            if (k == m)
            {
                count++;
                k = lps[k - 1];
            }
        }
        else
        {
            if (k != 0)
            {
                k = lps[k - 1];
            }
            else
            {
                j++;
            }
        }
    }
    printf("Number of times string 2 occurs in string 1: %d\n", count);
}

/*
Output:

Enter the string 1: hdjhdjhababababbakdjkdj
Enter the string 2: ab
Number of times string 2 occurs in string 1: 4

*/
