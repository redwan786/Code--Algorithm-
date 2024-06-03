#include <bits/stdc++.h>
using namespace std;

int node, edge;
int adj[100][100];
vector<int> T(node, 0); // A vector of size node with all elements set to 0


void MakeSet(int n){

}

/*
void Kruskal(){
    for(int i = 0; i < node; i++){
        MakeSet(i);
    }
    * sort the edges(u, v) increasing order by the weight
    * for each edge : 
    *       if FindSet(u) != FindSet(v):
    *           T = T U {(u, v)}
    *           union (FindSet(u),FindSet(v))
    
}*/

int main()
{
    cout << "Enter the number of nodes & edges: ";
    cin >> node >> edge;

    int n1, n2, n3;
    cout << "Enter edges with weights:" << endl;
    for (int i = 0; i < edge; i++)
    {
        cin >> n1 >> n2 >> n3;
        adj[n1][n2] = n3;
    }
   cout <<adj[1][3] << "inkyumhuj " << endl;//8


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

*/