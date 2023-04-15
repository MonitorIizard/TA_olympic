#include<stdio.h>

#define V 4
#define inf 50000

int next[V][V];

void Floyd(int dis[][V])
{
    for(int u=0; u < V; u++)
       { for(int v=0; v < V; v++)
           {  if (dis[u][v] == inf)
                    next[u][v] = -1;
              else
                    next[u][v] = v;
           }
       }

    for(int k=0; k < V; k++)
      { for(int u=0; u < V; u++)
          { for(int v=0; v < V; v++)
               if (dis[u][v] > dis[u][k]+ dis[k][v]) {
                     dis[u][v] = dis[u][k] + dis[k][v];
                     next[u][v] = next[u][k];                    // keep path from u to k
                 }
           }
      }

    /* for(int u=0; u < V; u++)                        // pair of u and v
       {  for(int v=0; v < V; v++)
             printf("%d ", next[u][v]);
          printf("\n");
       }*/
}

void print_path(int u, int v)
{   printf("%d ", u );
    while (u != v)  {
        u = next[u][v];
        printf("-> %d ", u);
    }

}

void main()
{ int graph[][V] = { {0, 3, inf, 7},
                     {8, 0, 2, inf},
                     {5, inf, 0, 1},
                     {2, inf, inf, 0} };
  Floyd(graph);
  print_path(2, 1);
}
