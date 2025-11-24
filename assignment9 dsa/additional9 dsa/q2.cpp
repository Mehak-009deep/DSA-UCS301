#include <bits/stdc++.h>
using namespace std;

// Directions for moving in grid
int dirR[4] = {1, -1, 0, 0};
int dirC[4] = {0, 0, 1, -1};

int dijkstraGrid(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Min-heap {cost, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // Distance matrix
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];

    pq.push({dist[0][0], 0, 0});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top[0];
        int r = top[1];
        int c = top[2];

        // If reached destination
        if (r == m - 1 && c == n - 1)
            return cost;

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nr = r + dirR[i];
            int nc = c + dirC[i];

            // Check bounds
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];

                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }
    }
    return -1; // Should not happen normally
}

// MAIN
int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int result = dijkstraGrid(grid);
    cout << "Minimum cost path = " << result << endl;

    return 0;
}

/*
================= SAMPLE INPUT =================
grid = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

================= SAMPLE OUTPUT =================
Minimum cost path = 21

Explanation path: 1 → 2 → 3 → 6 → 9
Total cost = 1 + 2 + 3 + 6 + 9 = 21
*/
