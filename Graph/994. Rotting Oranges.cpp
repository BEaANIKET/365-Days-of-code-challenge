class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        queue<pair<pair<int, int>, int>>q;
        int vis[n][m];

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(g[i][j] == 2){
                q.push({{i, j},{0}});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int time = 0;
        int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i=0; i<4; i++){
                int new_i = r + x[i];
                int new_j = c + y[i];

                if( new_i >= 0 && new_i<n && new_j>=0 && new_j<m && vis[new_i][new_j]!=2 && g[new_i][new_j]==1 ){
                    q.push({{new_i, new_j}, t+1});
                    vis[new_i][new_j] = 2;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j =0; j<m; j++){
                if(vis[i][j] != 2 && g[i][j] == 1){
                    return -1;
                }
            }
        }

        return time;
    }
};