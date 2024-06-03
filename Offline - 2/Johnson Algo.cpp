#include<bits/stdc++.h> // Include all standard C++ libraries
using namespace std;     // Use the standard namespace

#define INF 1e9         // Define a large value as infinity
#define NIL -1          // Define NIL as -1

int node, edge;         // Declare variables to store the number of nodes and edges
int adj[100][100];      // Declare an adjacency matrix to store the graph

// Function to create a new node and add edges from it to all other nodes with weight 0
void createGPrime(int source)
{
    for (int u = 0; u < node; u++)
    {
        adj[node][u] = 0; // Add an edge from the new node to all other nodes with weight 0
    }
}

// Bellman-Ford algorithm to detect negative weight cycles and find shortest paths
bool BellmanFord(int source, int h[], int pre_node[])
{
    int dist[node];                            // Array to store shortest distances
    for (int i = 0; i < node; i++)
    {
        dist[i] = INF;                         // Initialize all distances to infinity
    }
    dist[source] = 0;                          // Set the distance of the source node to 0
    int v = 0;
    int u = 0;

    int weight = adj[u][v];
    for (int i = 0; i < node - 1; i++)        // Relax edges (node-1) times
    {
        for ( u = 0; u < node; u++)
        {
            for ( v = 0; v < node; v++)
            {
                //int weight = adj[u][v];
                if (weight != 0 && dist[u] != INF && dist[v] > dist[u] + weight) // If there is an edge and we can get a shorter path
                {
                    dist[v] = dist[u] + weight;   // Update the distance of v
                    pre_node[v] = u;              // Update the predecessor of v
                }
            }
        }
    }

    // Check for negative weight cycles
    if (weight != 0 && dist[u] != INF && dist[v] > dist[u] + weight)
    {
        return false;  // Negative weight cycle detected
    }

    for (int i = 0; i < node; i++)
    {
        h[i] = dist[i];  // Store the shortest distances in h
    }

    return true;  // No negative weight cycle detected
}

// Dijkstra's algorithm with modified edge weights
void Dijkstra(int source, int weightPrime[], int dist[][100], int pre_node[])
{
    pair<int, int> pq[node * node];  // Priority queue to store nodes with their distances
    int pq_size = 0;
    for (int i = 0; i < node; i++)
    {
        dist[source][i] = INF;  // Initialize all distances to infinity
    }
    dist[source][source] = 0;  // Set the distance of the source node to 0
    pq[pq_size++] = make_pair(0, source);  // Add the source node to the priority queue

    while (pq_size > 0)
    {
        int min_dist = INF, min_idx = -1;
        for (int i = 0; i < pq_size; i++)  // Find the node with the minimum distance
        {
            if (pq[i].first < min_dist)
            {
                min_dist = pq[i].first;
                min_idx = i;
            }
        }

        int u = pq[min_idx].second;
        swap(pq[min_idx], pq[--pq_size]);  // Remove the minimum node from the priority queue

        if (min_dist > dist[source][u]) continue;  // If the node has already been processed, skip it

        for (int v = 0; v < node; v++)
        {
            int weight = adj[u][v] + weightPrime[u] - weightPrime[v];  // Calculate the modified edge weight
            if (weight != 0 && dist[source][v] > dist[source][u] + weight)  // If there is an edge and we can get a shorter path
            {
                dist[source][v] = dist[source][u] + weight;  // Update the distance of v
                pq[pq_size++] = make_pair(dist[source][v], v);  // Add v to the priority queue
                pre_node[v] = u;  // Update the predecessor of v
            }
        }
    }
}

// Function to print the shortest path from source to target
void PrintPath(int source, int target, int pre_node[])
{
    if (source == target)
    {
        cout << source;  // If source and target are the same, print the node
    }
    else if (pre_node[target] == NIL)
    {
        cout << "No path from " << source << " to " << target;  // If there is no path, print a message
    }
    else
    {
        PrintPath(source, pre_node[target], pre_node);  // Recursively print the path
        cout << " -> " << target;
    }
}

// Johnson's algorithm to find shortest paths between all pairs of nodes
void Johnson(int D[][100])
{
    createGPrime(node);  // Create a new node and add edges to all other nodes

    int h[node], pre_node[node];
    for (int i = 0; i < node; i++)
    {
        h[i] = 0;
        pre_node[i] = NIL;
    }
    if (!BellmanFord(node, h, pre_node))  // Run Bellman-Ford from the new node
    {
        cout << "The input graph has a negative weight cycle" << endl;
        return;
    }

    // Reweight the edges by adding the values from h
    for (int u = 0; u < node; u++)
    {
        for (int v = 0; v < node; v++)
        {
            int weight = adj[u][v];
            if (weight != 0)
            {
                adj[u][v] = weight + h[u] - h[v];
            }
        }
    }

    cout << "Shortest paths between all pairs of nodes:" << endl;
    for (int u = 0; u < node; u++)
    {
        Dijkstra(u, h, D, pre_node);  // Run Dijkstra from each node
        for (int v = 0; v < node; v++)
        {
            if (D[u][v] == INF)
            {
                cout << u << "->" << v << ": No path" << endl;  // If there is no path, print a message
            }
            else
            {
                cout << u << "->" << v << ": Cost = " << D[u][v] << ", Path: ";
                PrintPath(u, v, pre_node);  // Print the shortest path
                cout << endl;
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("johnson algo.txt", "r", stdin);  // Open an input file
    cout << "Enter the number of nodes & edges: ";
    cin >> node >> edge;  // Read the number of nodes and edges

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < node; j++)
        {
            adj[i][j] = 0;  // Initialize the adjacency matrix with 0
        }
    }

    cout << "Enter edges with weights :" << endl;
    int from, to, weight;
    for (int i = 0; i < edge; i++)
    {
        cin >> from >> to >> weight;  // Read the edges and their weights
        adj[from][to] = weight;  // Add the edge to the adjacency matrix
    }
    int shortestPaths[100][100];
    Johnson(shortestPaths); // Call Johnson's algorithm to find all-pairs shortest paths

    return 0;
}

