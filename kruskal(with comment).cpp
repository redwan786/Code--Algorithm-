#include<bits/stdc++.h>
using namespace std;

// Function to find the representative (root) of the set containing x
int findSet(int x, vector<int> &parent)
{
    // Path compression technique to flatten the structure
    if (parent[x] != x)
    {
        parent[x] = findSet(parent[x], parent); // Recursively find and compress path
    }
    return parent[x]; // Return the root of the set containing x
}

// Function to unite two sets based on their ranks
void unionSets(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int rootX = findSet(x, parent); // Find root of x's set
    int rootY = findSet(y, parent); // Find root of y's set

    // Union by rank
    if (rootX != rootY)
    {
        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX; // Attach rootY under rootX
        }
        else if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY; // Attach rootX under rootY
        }
        else
        {
            parent[rootY] = rootX; // Arbitrary attachment, increment rank of rootX
            rank[rootX]++;
        }
    }
}

// Comparator function to sort edges by weight
bool sortByWeight(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    return a.second < b.second; // Compare weights of two edges
}

// Kruskal's algorithm to find Minimum Spanning Tree (MST)
pair<vector<pair<int, int>>, int> kruskal(int V, vector<pair<pair<int, int>, int>> &edges)
{
    vector<pair<int, int>> mst; // Stores edges of the MST
    vector<int> parent(V), rank(V, 0); // Parent and rank arrays for Union-Find
    int totalCost = 0; // Total cost of the MST

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; ++i)
    {
        parent[i] = i;
    }

    // Sort edges based on weight
    sort(edges.begin(), edges.end(), sortByWeight);

    // Process each edge in increasing order of weight
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int weight = edges[i].second;

        // Check if adding this edge forms a cycle
        if (findSet(u, parent) != findSet(v, parent))
        {
            mst.push_back({u, v}); // Add edge to MST
            totalCost += weight; // Add weight to total cost
            unionSets(u, v, parent, rank); // Union u and v sets
        }
    }

    return {mst, totalCost}; // Return MST edges and total cost
}

// Main function
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Initialize vector of edges
    vector<pair<pair<int, int>, int>> edges(E);

    cout << "Enter the edges with their weights (u v w):" << endl;
    // Input edges and their weights
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
    }

    // Execute Kruskal's algorithm to find MST
    auto result = kruskal(V, edges);
    vector<pair<int, int>> mst = result.first; // MST edges
    int totalCost = result.second; // Total cost of MST

    // Output MST edges and additional information
    cout << "T={";
    int mstIndex = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        // Check if edge is in MST or not
        if (mstIndex < mst.size() && edges[i].first.first == mst[mstIndex].first && edges[i].first.second == mst[mstIndex].second)
        {
            cout << "(" << edges[i].first.first << "," << edges[i].first.second << ")";
            ++mstIndex;
        }
        else
        {
            cout << "(" << edges[i].first.first << "," << edges[i].first.second << ")x"; // Indicate not in MST
        }
        if (i != edges.size() - 1) cout << ",";
    }
    cout << "} ; here (a,b)x means this pair is not allowed to sit here" << endl;

    // Output total cost and number of edges in MST
    cout << "Cost= " << totalCost << endl;
    cout << "Total edges= " << mst.size() << endl;

    return 0;
}


/*

Enter the number of vertices: 7
Enter the number of edges: 11
Enter the edges with their weights (u v w):
0 1 2
0 5 14
0 6 8
6 5 21
1 5 25
4 5 13
2 5 17
1 2 19
2 3 9
2 4 5
3 4 1
T={(3,4),(0,1),(2,4),(0,6),(2,3)x,(4,5),(0,5),(2,5)x,(1,2)x,(6,5)x,(1,5)x} ; here (a,b)x means this pair is not allowed to sit here
Cost= 43
Total edges= 6

*/
