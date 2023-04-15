#include <stdio.h>

#define V 9
#define INT_MAX 50000

int minDistance(int dist[], bool inTree[])
{ int min = INT_MAX, min_index;

for (int v = 0; v < V; v++)
  if (inTree[v] == false && dist[v] <= min)
      { min = dist[v];
        min_index = v;
      }

 return min_index;
}

int printSolution(int dist[],int parent[], int n)
{ int i;
  printf("Vertex Distance from Source\n");
  for (i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);

  printf("\n");
  for (i = 0; i < V; i++)
     printf("\t%d", parent[i]);
}

void dijkstra(int graph[V][V], int src)
{ int dist[V];                 // dist[i] will hold the shortest distance from src to i
  bool inTree[V];              // will true if vertex i is included in shortest
  int parent[V];               // parent


  for (int i = 0; i < V; i++) // initial dist vector
        dist[i] = INT_MAX, parent[i] = -1, inTree[i] = false;

  dist[src] = 0;                                           // assign start node is 0

   // Find shortest path for all vertices
   for (int i = 0; i < V-1; i++)
     { int u = minDistance(dist, inTree);                      // find node u with minimum distance from node src
       inTree[u] = true;             // select node u
       for (int v = 0; v < V; v++)   // update weights
           if (inTree[v] == false && graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v])
               {  dist[v] = dist[u] + graph[u][v];
                  parent[v] = u;
               }
     }

 printSolution(dist, parent, V);
}

int main()
{ int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                    };

dijkstra(graph, 0);

return 0;
}
