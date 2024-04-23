class Solution {
public:

    vector<vector<int>>dir{{-1,0},{0,1},{1,0},{0,-1}};

    bool isSafe(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m) {
            return true;
        }
        return false;
    }


    void DFS (vector<vector<int>> &land, int x, int y, int &x2, int &y2, vector<vector<bool>> &vis, int n, int m){

       
        vis[x][y] = true;

        x2 = max(x2, x);
        y2 = max(y2, y);

        for(auto d : dir){

            int newX = x + d[0];
            int newY = y + d[1];

            if( isSafe(newX, newY, n, m) && land[newX][newY] && !vis[newX][newY] ){
                DFS(land, newX, newY, x2, y2, vis, n, m);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        

        int n = land.size();
        int m = land[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && land[i][j]){
                    int x2 = 0, y2 = 0;
                    DFS(land, i, j, x2, y2, vis, n, m);
                    ans.push_back({i, j, x2, y2});
                }
            }
        }

        return ans ;
    }
};