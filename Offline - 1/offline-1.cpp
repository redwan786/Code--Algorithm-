//****************  0 based  ****************//

#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3
#define INF 1e9
#define NIL -1

int adj[100][100];
int color[100];
int node, edge, weight;
vector<int>vktr;
int dist[100];
string pre_node[100];


//************ For Initialize ************//

void Initialize_Single_Source(int source)
{
    for(int i = 0; i < node; i++)
    {
        dist[i] = INF;
        pre_node[i] = NIL;
    }
    dist[source] = 0;

}


Relax(int u, int v, int w)
{
    if(dist[v] > dist[u] + w)
    {
        dist[v] = dist[u] + w;
        pre_node[v] = u;

    }
}


// **********  For Topological Sort  ************//

void dfsVisit(int x)
{
    color[x] = GRAY;
    //cout << x << " ";
    for(int i = 0; i < node; i++)
    {
        if(adj[x][i] >= -2 && color[i] == WHITE)
        {
            dfsVisit(i);
        }
    }
    color[x] = BLACK;

    vktr.push_back(x);

    //cout << x << " "; // Ulta print korte hbe, so put this value store in a vector then print it reversely.

}


void dfs()
{
    for(int i = 0; i < node; i++)
    {
        color[i] = WHITE;
    }
    for(int i = 0; i < node; i++)
    {
        if(color[i] == WHITE)
        {
            cout << "Topological Sort : ";
            dfsVisit(i);
            //cout << endl;
        }
    }
}

int main()
{
    //freopen("Adjacency Matrix Input.txt","r", stdin); // input from a txt file
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge ;

    int n1, n2, n3;

    cout << "Enter values : " << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2 >> n3;
        //adj[n1][n2] = 1;
        //adj[n2][n1] = 1;
        adj[n1][n2] = n3;

    }

    dfs();

    for(int i = vktr.size() - 1; i >= 0; i--)
    {
        cout << vktr[i] << " ";
    }
    cout << endl << endl;

    int source;
    cout << "Enter the source node : ";
    cin >> source;
    Initialize_Single_Source(source);


    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            if(adj[i][j] >= -2 )
            {
                Relax(vktr[i], vktr[j], adj[i][j]);
            }
        }
    }

    for(int i = 0; i < node; i++)
    {
        cout << "For Node : " << i << endl << "cost: " << dist[i] << endl << endl;

    }
}


































