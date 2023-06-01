#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        
        vector<vector<int>> directions = {{1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {-1, 1}};
        
        vector<int> dist(n * n, INT_MAX);
        dist[0] = 1;
        
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            
            int x = idx / n;
            int y = idx % n;
            
            for (auto dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                int nidx = nx * n + ny;
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && dist[nidx] == INT_MAX) {
                    dist[nidx] = dist[idx] + 1;
                    q.push(nidx);
                }
            }
        }
        
        return (dist[n * n - 1] == INT_MAX) ? -1 : dist[n * n - 1];
    }
};
