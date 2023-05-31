/*********************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     17
Program Name:   Write a C/C++ program to find all the paths between any two vertices of a connected graph.
Date:           09/06/2022
*********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void printPath(int *path, int path_size);
void printAllPaths(int *path, int path_size, int start, int end, int **graph, int graph_size);
void printAllPathsUtil(int start, int end, int **graph, int graph_size);
void printAllPathsBetweenTwoVertices(int **graph, int graph_size);

int main()
{
    int graph_size = 5;
    int **graph = (int **)malloc(graph_size * sizeof(int *));
    int i, j;
    for (i = 0; i < graph_size; i++)
    {
        graph[i] = (int *)malloc(graph_size * sizeof(int));
    }
    for (i = 0; i < graph_size; i++)
    {
        for (j = 0; j < graph_size; j++)
        {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][3] = 1;
    graph[2][4] = 1;
    graph[3][4] = 1;
    printAllPathsBetweenTwoVertices(graph, graph_size);
    return 0;
}

void printPath(int *path, int path_size)
{
    int i;
    for (i = 0; i < path_size; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void printAllPaths(int *path, int path_size, int start, int end, int **graph, int graph_size)
{
    if (start == end)
    {
        printPath(path, path_size);
    }
    else
    {
        int i;
        for (i = 0; i < graph_size; i++)
        {
            if (graph[start][i] == 1)
            {
                path[path_size] = i;
                printAllPaths(path, path_size + 1, i, end, graph, graph_size);
            }
        }
    }
}

void printAllPathsUtil(int start, int end, int **graph, int graph_size)
{
    int *path = (int *)malloc(graph_size * sizeof(int));
    printAllPaths(path, 0, start, end, graph, graph_size);
    free(path);
}

void printAllPathsBetweenTwoVertices(int **graph, int graph_size)
{
    int i;
    for (i = 0; i < graph_size; i++)
    {
        printAllPathsUtil(i, graph_size - 1, graph, graph_size);
    }
}
