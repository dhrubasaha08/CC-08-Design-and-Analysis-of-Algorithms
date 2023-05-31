/************************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     16
Program Name:   Write a C/C++ program to find a minimal spanning tree from a weighted connected graph by Prim's algorithm.
Date:           3/7/2022
*************************************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 9999999
#define V 5

int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

void main()
{
    int no_edge, selected[V], x, y;

    memset(selected, false, sizeof(selected));
    no_edge = 0;
    selected[0] = true;
    printf("Edge : Weight\n");

    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }
}

/*
Output:

Edge : Weight
0 - 1 : 9
1 - 3 : 19
3 - 4 : 31
3 - 2 : 51

*/