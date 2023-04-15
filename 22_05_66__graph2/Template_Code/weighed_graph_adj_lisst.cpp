#include <bits/stdc++.h>

using namespace std;

void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt)
{   adj[u].push_back({v, wt});
}

void printGraph(vector<pair<int,int> > adj[], int V)
{ int v, w;

  for (int u = 1; u < V; u++)
    {  cout << u << " : ";

       for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
          {  v = it->first;
             w = it->second;
             cout << " " << v << ":"  << w;
          }

        cout << "\n";
    }
}

int main()
{   int V = 5;

    vector<pair<int, int> > adj[V];

    addEdge(adj, 1, 2, 5);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 4, 6);
    addEdge(adj, 3, 4, 5);
    addEdge(adj, 4, 1, 2);

    printGraph(adj, V);

    return 0;
}
