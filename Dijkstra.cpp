#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define INF 1e9
#define NIL -1

int adj[100][100];
int color[100];
int node, edge;
vector<int> vktr;
vector<int> pre_node[100];
int dist[100];


void Initialize_Single_Source(int source)
{
    for(int i = 0; i < node; i++)
    {
        dist[i] = INF;
        pre_node[i].clear();
        //pre_node[i].push_back(NIL);

    }
    dist[source] = 0;
}

int Extract_Min(vector<int>& Q)
{
    int minDist = INF;
    int u = -1;
    for (int i = 0; i < node; ++i)
    {
        if (color[i] == WHITE && dist[i] < minDist)
        {
            minDist = dist[i];
            u = i;
        }
    }
    return u;
}

void Relax(int u, int v, int w)
{
    if(dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        pre_node[v] = pre_node[u];
        pre_node[v].push_back(u);
    }
}



void Dijkstra(int source)
{
    Initialize_Single_Source(source);
    vector<int> Q;
    for(int i = 0; i < node; i++)
    {
        Q.push_back(i);
        color[i] = WHITE;
    }

    while (!Q.empty())
    {
        int u = Extract_Min(Q);
        if (u == -1)
        {
            break;
        }

        color[u] = BLACK;
        for (int v = 0; v < node; v++)
        {
            if (adj[u][v] != 0)
            {
                Relax(u, v, adj[u][v]);
            }
        }
    }
}



int main()
{
    //freopen("dijkstra.txt","r", stdin);
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge ;

    int n1, n2, n3;

    cout << "Enter edges with weights:" << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2 >> n3;
        adj[n1][n2] = n3;
    }

    int source;
    cout << "Enter the source node : ";
    cin >> source;

    Dijkstra(source);

    cout << "Shortest paths from node " << source << endl;
    for(int i = 0; i < node; i++)
    {
        cout << "Node " << i << ": ";
        if(dist[i] == INF)
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
0 1 10
0 3 5
4 0 7
1 3 2
3 1 3
1 2 1
3 2 9
3 4 2
2 4 4
4 2 6
0

*/


/*

Enter the number of nodes & edges : 5 10
Enter edges with weights:
0 1 10
0 3 5
4 0 7
1 3 2
3 1 3
1 2 1
3 2 9
3 4 2
2 4 4
4 2 6
Enter the source node : 0
Shortest paths from node 0
Node 0: Cost: 0, Path: 0
Node 1: Cost: 8, Path: 0 -> 3 -> 1
Node 2: Cost: 9, Path: 0 -> 3 -> 1 -> 2
Node 3: Cost: 5, Path: 0 -> 3
Node 4: Cost: 7, Path: 0 -> 3 -> 4

*/
