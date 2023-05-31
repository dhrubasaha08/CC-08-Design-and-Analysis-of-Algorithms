/*****************************************************************************************************************
Name:           Dhruba Saha
Roll No:        B.Sc(Sem-IV)-04
Program No:     14
Program Name:   Write a C/C++ program to find a spanning tree from a connected graph by using Breadth First Search.
Date:           3/7/2022
******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node
{
    int vertex;
    struct node *next;
};

struct queue
{
    int items[SIZE];
    int front;
    int rear;
};

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct node *createNode(int v)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct queue *createQueue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct node **)malloc(vertices * sizeof(struct node *));
    graph->visited = (int *)malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void enqueue(struct queue *q, int item)
{
    if (q->rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = item;
    if (q->front == -1)
        q->front = 0;
}

int dequeue(struct queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    return item;
}

int isEmpty(struct queue *q)
{
    if (q->front == -1)
        return 1;
    else
        return 0;
}

void printQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = q->front; i <= q->rear; i++)
        printf("%d ", q->items[i]);
    printf("\n");
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp)
        {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(struct Graph *graph, int startVertex)
{
    struct queue *q = createQueue();
    enqueue(q, startVertex);
    graph->visited[startVertex] = 1;
    while (!isEmpty(q))
    {
        int v = dequeue(q);
        printf("%d ", v);
        struct node *temp = graph->adjLists[v];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                enqueue(q, adjVertex);
                graph->visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void main()
{
    struct Graph *graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    printf("\n");
    bfs(graph, 0);
    printf("\n");
}

/*
Output:

 Adjacency list of vertex 0
 head -> 2-> 1

 Adjacency list of vertex 1
 head -> 4-> 3-> 2

 Adjacency list of vertex 2
 head -> 3

 Adjacency list of vertex 3
 head -> 4

 Adjacency list of vertex 4
 head 

0 2 1 3 4 

*/