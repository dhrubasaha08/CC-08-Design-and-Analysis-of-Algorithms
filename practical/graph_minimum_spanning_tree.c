#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INFINITY 65535

typedef struct {
  int adjvex[MAX_VERTEX_NUM];
  int lowcost[MAX_VERTEX_NUM];
  int num;
} MGraph;

typedef struct {
  int data;
  int lowcost;
  int parent;
  int num;
} Vertex;

void CreateMGraph(MGraph *G) {
  int i, j, k, w;
  printf("please input the number of vertexes:\n");
  scanf("%d", &G->num);
  for (i = 0; i < G->num; i++) {
    printf("please input the adjvex of vertex %d:\n", i);
    for (j = 0; j < G->num; j++) {
      scanf("%d", &k);
      G->adjvex[i][j] = k;
    }
  }
  for (i = 0; i < G->num; i++) {
    for (j = 0; j < G->num; j++) {
      if (G->adjvex[i][j] != 0) {
        printf("please input the weight of edge (%d, %d):\n", i, j);
        scanf("%d", &w);
        G->adjvex[i][j] = w;
      }
    }
  }
}

void DFS(MGraph G, Vertex V[], int i) {
  int j;
  V[i].num = 1;
  for (j = 0; j < G.num; j++) {
    if (G.adjvex[i][j] != 0 && V[j].num == 0) {
      V[j].parent = i;
      V[j].lowcost = G.adjvex[i][j];
      DFS(G, V, j);
    }
  }
}

void FindMinSpanTree(MGraph G, Vertex V[]) {
  int i, j, k, w;
  for (i = 0; i < G.num; i++) {
    V[i].num = 0;
  }
  for (i = 0; i < G.num; i++) {
    if (V[i].num == 0) {
      DFS(G, V, i);
    }
  }
}

int main() {
  MGraph G;
  Vertex V[MAX_VERTEX_NUM];
  CreateMGraph(&G);
  FindMinSpanTree(G, V);
  return 0;
}