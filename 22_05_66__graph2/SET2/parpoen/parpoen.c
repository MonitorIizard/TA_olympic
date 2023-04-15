#include<stdio.h>


int n, m;
int g[1000][1000];

int min(int x, int y)
{ return (x<y)?x:y;
}

int max(int x, int y)
{ return (x>y)?x:y;
}

void floyd()
{  for (int k = 1; k <= n; k++)
     for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
           g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));     // find path from source to dest that has maximum smallest edges.
}

int main()
{   int  u, v, w, fr, to;

    scanf("%d %d", &n, &m);
    memset(g, 0, sizeof(g));

    for (int i = 0; i < m; i++)
      {  scanf("%d%d%d", &u, &v, &w);
         g[u][v] = g[v][u] = w;
      }

     scanf("%d%d%d", &fr, &to, &w);
     floyd();
     printf("%.lf", ceil((double) w / (g[fr][to] - 1)));

    return 0;
}
