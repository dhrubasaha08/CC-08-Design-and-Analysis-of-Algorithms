/***************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     5
Program Name:   Write a robust C program to find all prime numbers upto a N.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime();

int main()
{
	int n;
    printf("Enter N:");
    scanf("%d",&n);
	prime(n);
	return 0;
}

void prime(int n)
{
	int prime[n+1], i, j;
	for(i = 0; i <= n; i++)
		prime[i] = 1;
		
	for(i = 2; i <= sqrt(n); i++)
	{
		if(prime[i] == 1)
		{
			for(j = i*i; j <= n; j += i)
				prime[j] = 0;
		}
	}

	for(i = 2; i <= n; i++)
	{
		if(prime[i] == 1)
			printf("%d ", i);
	}
}