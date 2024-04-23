// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1



class Solution {
public:

    vector<int>x = {-1,0,1,0};
    vector<int>y = {0,1,0,-1};

    void solve(vector<vector<char>>& g, vector<vector<bool>> &v, int i, int j, int n, int m){

        if(i < 0 || i >= n || j < 0 || j >= m || !v[i][j] || g[i][j] != '1') {
            return;
        }

        v[i][j] = false;


        for(int k=0; k<4; k++){
            int newX = i+x[k];
            int newY = j+y[k];

            solve(g, v, newX, newY, n, m);
        }
        return ;
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        if(n == 0) return 0; 
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, true));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] && grid[i][j]=='1' ){
                    ans++;
                    solve(grid, visited, i, j, n, m); 
                }      
            }
        }

        return ans;
    }
};