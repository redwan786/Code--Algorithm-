#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int node, edge;
int parent[100];
int dis[100];




void bfs(int startingNode)
{
    for(int i = 0; i < node; i++)
    {
        color[i] = WHITE;
        dis[i] = INT_MIN;
        parent[i] = -1;
    }
    dis[startingNode] = 0;
    parent[startingNode] = -1;

    queue<int> q;
    q.push(startingNode);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        color[x] = GRAY;

        cout << x << " ";
        for(int i = 0; i < node; i++)
        {
            if(adj[x][i] == 1 && color[i] == WHITE)
            {
                // x er neighbor i
                // x no node ta holo i no node er parent
                dis[i] = dis[x] + 1;
                parent[i] = x;
                q.push(i);
            }
        }
        color[x] = BLACK;
    }
}



int main()
{
    freopen("Input bfs.txt","r", stdin); // input from a txt file
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge;

    int n1, n2;

    cout << "Enter values : " << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }
    int startingNode;
    cout << "Enter Starting Node : " << endl;
    cin >> startingNode;
    cout << "DFS traversal: ";

    bfs(startingNode);
    cout << endl << parent[5] << endl; // node 5 er parent print hbe
    cout << dis[6] << endl; // node 6 er distance print hbe starting node theke




}





