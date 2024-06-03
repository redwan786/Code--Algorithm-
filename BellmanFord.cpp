#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define NIL -1

int adj[100][100];
vector<int> pre_node[100];
int node, edge;
int dist[100];

void Initialize_Single_Source(int source)
{
    for (int i = 0; i < node; i++)
    {
        dist[i] = INF;
        pre_node[i].clear();
    }
    dist[source] = 0;
}

void Relax(int u, int v, int w)
{
    if (dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        pre_node[v] = pre_node[u];
        pre_node[v].push_back(u);
    }
}

int BellmanFord(int source)
{
    Initialize_Single_Source(source);
    int u, v;
    for (int i = 0; i < node - 1; i++)
    {
        for (u = 0; u < node; u++)
        {
            for (v = 0; v < node; v++)
            {
                if (adj[u][v] != 0)
                {
                    Relax(u, v, adj[u][v]);
                }
            }
        }
    }


    // Check for negative weight cycles
    if (dist[v] > dist[u] + adj[u][v])
    {
        cout << "Negative weight cycle detected!" << endl;
        return 0; // Negative weight cycle found
    }

    return 0;
}

int main()
{
    //freopen("BellmanFord.txt", "r", stdin);
    cout << "Enter the number of nodes & edges: ";
    cin >> node >> edge;

    int n1, n2, n3;
    cout << "Enter edges with weights:" << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2 >> n3;
        adj[n1][n2] = n3;
    }


    int source;
    cout << "Enter the source node: ";
    cin >> source;


    BellmanFord(source);

    cout << "Shortest paths from node " << source << endl;
    for (int i = 0; i < node; ++i)
    {
        cout << "Node " << i << ": ";
        if (dist[i] == INF)
            cout << "No path";
        else
        {
            cout << "Cost: " << dist[i] << ", Path: ";
            for(int j = 0; j < pre_node[i].size(); j++)
            {
                cout << pre_node[i][j] << " -> ";
            }
            cout << i;
        }
        cout << endl;
    }

    return 0;
}

/*

5 10
0 1 6
0 3 7
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 2 7
4 0 2
0

*/

/*

Enter the number of nodes & edges: 5 10
Enter edges with weights:
0 1 6
0 3 7
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 2 7
4 0 2
Enter the source node: 0
Shortest paths from node 0
Node 0: Cost: 0, Path: 0
Node 1: Cost: 2, Path: 0 -> 3 -> 2 -> 1
Node 2: Cost: 4, Path: 0 -> 3 -> 2
Node 3: Cost: 7, Path: 0 -> 3
Node 4: Cost: -2, Path: 0 -> 3 -> 2 -> 1 -> 4

*/
