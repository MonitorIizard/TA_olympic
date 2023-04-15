#include<stdio.h>

#define V 9
#define FALSE -1
#define TRUE 1
#define inf  50000

void Dijkstra(int g[][V], int start)
{    int i, j, v, w, weight, dist;
     int intree[1000], distance[1000], parent[1000];

     for(i=0; i < V;  i++) {
         intree[i] = FALSE;
         distance[i] = inf;
          parent[i] = -1;
      }

      distance[start] = 0; 	                      // initial distance from start vertex
      v = start;

    while( intree[v] == FALSE)
     {     intree[v] = TRUE;		                                // change status of vertex v
           for(i=0; i < V; i++) 	                               // update distance of each vertex
            {  if(distance[i] > distance[v] + g[v][i])
                 {   distance[i] = distance[v]  + g[v][i];
                     parent[i] = v;                               // update parent of vertex i
                 }
           }
          v = -1;
          dist = inf;
         for(i = 0; i < V; i++)
              if( (intree[i] == FALSE) && (dist > distance[i]) )
                   {  dist = distance[i];
                      printf("%d -- \n",dist);
                      v = i;
                   }
    }

     for(int i=0;i<V;i++)
        printf("%d ", distance[i]);
     printf("\n");

     for(int i=0;i<V;i++)
        printf("%d ", parent[i]);


 }

void main()
{     int graph[V][V] = {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    Dijkstra(graph, 0);
}
