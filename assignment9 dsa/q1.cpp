#include <bits/stdc++.h>
using namespace std;

/* ======================================================
                BREADTH FIRST SEARCH (BFS)
   ====================================================== */
void BFS(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

/* ======================================================
                DEPTH FIRST SEARCH (DFS)
   ====================================================== */
void DFSUtil(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!visited[neigh])
            DFSUtil(neigh, adj, visited);
    }
}

void DFS(int start, vector<vector<int>> &adj, int n) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

/* ======================================================
                KRUSKAL'S ALGORITHM – MST
   ====================================================== */
class DSU {
public:
    vector<int> parent, rank_arr;

    DSU(int n) {
        parent.resize(n);
        rank_arr.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);

        if (rx == ry) return;

        if (rank_arr[rx] < rank_arr[ry])
            parent[rx] = ry;
        else if (rank_arr[rx] > rank_arr[ry])
            parent[ry] = rx;
        else {
            parent[ry] = rx;
            rank_arr[rx]++;
        }
    }
};

void KruskalMST(vector<vector<int>> &edges, int n) {
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    DSU dsu(n);

    int mst_cost = 0;
    cout << "Kruskal MST Edges:\n";

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];

        if (dsu.find(u) != dsu.find(v)) {
            cout << u << " - " << v << " weight=" << w << endl;
            mst_cost += w;
            dsu.unite(u, v);
        }
    }

    cout << "Total Minimum Cost = " << mst_cost << endl;
}

/* ======================================================
                PRIM'S ALGORITHM – MST
   ====================================================== */
void PrimMST(int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0});

    int mst_cost = 0;

    cout << "Prim MST Edges:\n";

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        mst_cost += wt;

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Total Minimum Cost = " << mst_cost << endl;
}

/* ======================================================
                DIJKSTRA'S SHORTEST PATH
   ====================================================== */
void Dijkstra(int src, int n, vector<vector<pair<int,int>>> &adj) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra Shortest Distances from source " << src << ":\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << endl;
}

/* ======================================================
                        MAIN PROGRAM
   ====================================================== */
int main() {

    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // For BFS & DFS (unweighted)
    vector<vector<int>> adj(n);

    // For Prim & Dijkstra (weighted)
    vector<vector<pair<int,int>>> adjW(n);

    // Edge list for Kruskal
    vector<vector<int>> edges;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        adj[v].push_back(u);

        adjW[u].push_back({v, w});
        adjW[v].push_back({u, w});

        edges.push_back({u, v, w});
    }

    cout << "\n--- BFS ---\n";
    BFS(0, adj, n);

    cout << "\n--- DFS ---\n";
    DFS(0, adj, n);

    cout << "\n--- Kruskal MST ---\n";
    KruskalMST(edges, n);

    cout << "\n--- Prim MST ---\n";
    PrimMST(n, adjW);

    cout << "\n--- Dijkstra ---\n";
    Dijkstra(0, n, adjW);

    return 0;
}


/*
======================== SAMPLE INPUT ========================
Enter number of vertices: 5
Enter number of edges: 6
Enter edges (u v w):
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2

======================== SAMPLE OUTPUT ========================

--- BFS ---
BFS Traversal: 0 1 2 3 4

--- DFS ---
DFS Traversal: 0 1 2 4 3

--- Kruskal MST ---
0 - 1 weight=2
1 - 2 weight=1
2 - 4 weight=3
3 - 4 weight=2
Total Minimum Cost = 8

--- Prim MST ---
Prim MST Edges:
Total Minimum Cost = 8

--- Dijkstra ---
Dijkstra Shortest Distances from source 0:
Node 0 : 0
Node 1 : 2
Node 2 : 3
Node 3 : 9
Node 4 : 6
*/
