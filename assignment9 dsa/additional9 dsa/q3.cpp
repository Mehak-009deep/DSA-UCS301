#include <bits/stdc++.h>
using namespace std;

// Function to compute Network Delay Time
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    // Create adjacency list: graph[u] = {v, w}
    vector<vector<pair<int,int>>> graph(N + 1);

    for (auto &t : times) {
        int u = t[0];
        int v = t[1];
        int w = t[2];
        graph[u].push_back({v, w});
    }

    // Min-heap for Dijkstra: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        auto [currentDist, node] = pq.top();
        pq.pop();

        // If already found better path, skip
        if (currentDist > dist[node]) continue;

        for (auto &edge : graph[node]) {
            int next = edge.first;
            int weight = edge.second;

            if (currentDist + weight < dist[next]) {
                dist[next] = currentDist + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // Find maximum time to reach all nodes
    int maxTime = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) return -1; // unreachable node
        maxTime = max(maxTime, dist[i]);
    }

    return maxTime;
}

int main() {
    int N = 4;
    int K = 2;

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int ans = networkDelayTime(times, N, K);
    cout << "Network Delay Time = " << ans << endl;

    return 0;
}


/*
================ SAMPLE INPUT =================
N = 4
K = 2
times = [
    [2, 1, 1],
    [2, 3, 1],
    [3, 4, 1]
]

================ SAMPLE OUTPUT ================
Network Delay Time = 2

Explanation:
Signal starts from node 2:
2 → 1 (1)
2 → 3 (1)
3 → 4 (1)

Longest time = 2 (to reach node 4)

*/
