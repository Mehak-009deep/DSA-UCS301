#include <iostream>
#include <vector>
using namespace std;

// Depth First Search
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neigh : adj[node]) {
        if (!visited[neigh])
            dfs(neigh, adj, visited);
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // because undirected
    }

    vector<bool> visited(V, false);
    int components = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;   // one complete connected component found
        }
    }

    cout << "Number of connected components = " << components << endl;

    return 0;
}

/*
---------------- SAMPLE INPUT ----------------
5 3
0 1
1 2
3 4

---------------- SAMPLE OUTPUT ----------------
Number of connected components = 2
*/
