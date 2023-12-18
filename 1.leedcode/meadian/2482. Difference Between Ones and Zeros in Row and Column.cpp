class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int, pair<int, int>> row;
        map<int, pair<int, int>> col;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    row[i].first++;
                } else {
                    row[i].second++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 0) { 
                    col[i].first++;
                } else {
                    col[i].second++;
                }
            }
        }

        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=(row[i].second + col[j].second) - (row[i].first + col[j].first);
                ans[i][j]=val;
            }
        }
        return ans;
    }
};
