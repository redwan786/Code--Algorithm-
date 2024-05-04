#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("Adjacency Matrix Input.txt","r", stdin); // input from a txt file
    int node, edge;
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge;
    vector<vector<int>> adj(edge, vector<int>(edge, 0));

    int n1, n2;

    cout << "Enter values : " << endl;
    for(int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2;
        adj[n1][n2] = 1;
        adj[n2][n1] = 1;
    }

    cout <<endl << "Neighbor :" << endl;
    for(int i = 0; i < node; i++)
    {
        cout << i << "-> ";
        for(int j = 0; j < node; j++)
        {
            if(adj[i][j] == 1){
               cout << j << " ";
            }
        }
        cout << endl;
    }

}
