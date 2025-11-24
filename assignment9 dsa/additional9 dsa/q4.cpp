#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int m = grid.size(), n = grid[0].size();

    // Boundary or water or already visited → stop
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (grid[r][c] == 0 || visited[r][c]) return;

    visited[r][c] = true;

    // Explore horizontal + vertical
    dfs(r + 1, c, grid, visited);
    dfs(r - 1, c, grid, visited);
    dfs(r, c + 1, grid, visited);
    dfs(r, c - 1, grid, visited);
}

int numIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int count = 0;

    // Traverse entire grid
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            // Start DFS if land and not visited
            if (grid[r][c] == 1 && !visited[r][c]) {
                count++;
                dfs(r, c, grid, visited);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0},
        {0, 1, 0},
        {1, 0, 1}
    };

    cout << "Number of Islands = " << numIslands(grid) << endl;
    return 0;
}

/*
==================== SAMPLE INPUT ====================
grid = [
  [1,1,0],
  [0,1,0],
  [1,0,1]
]

==================== SAMPLE OUTPUT ===================
Number of Islands = 3

Explanation:
Island 1: cells connected at (0,0), (0,1), (1,1)
Island 2: cell at (2,0)
Island 3: cell at (2,2)
*/
