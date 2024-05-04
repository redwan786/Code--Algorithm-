#include<bits/stdc++.h>
using namespace std;

#define WHITE 1
#define GRAY 2
#define BLACK 3

int adj[100][100];
int color[100];
int node, edge;

int Time = 1;
int sTime[100];
int fTime[100];



void dfsVisit(int x)
{
    color[x] = GRAY;
    cout << x << " ";
    sTime[x] = Time;
    Time++;
    for(int i = 0; i < node; i++)
    {
        if(adj[x][i] == 1 && color[i] == WHITE)
        {
            dfsVisit(i);
        }
    }
    color[x] = BLACK;
    fTime[x] = Time;
    Time++;

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
            dfsVisit(i);
        }
    }
}




int main()
{
    freopen("Adjacency Matrix Input.txt","r", stdin); // input from a txt file
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
    cout << "DFS traversal: ";

    dfs();

    cout << endl;
    for(int i = 0; i< node; i++)
    {
        cout << "Node-" << (char) ('A' + i) << " " << sTime[i] << " " << fTime[i] << endl;
    }


}

//Bujhini





