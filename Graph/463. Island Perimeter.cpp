class Solution {
public:

    vector<int>x = {-1,0,1,0};
    vector<int>y = {0,1,0,-1};

    int islandPerimeter(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int newX = i+x[k];
                        int newY = j+y[k];
                        if( newX < n && newX >= 0 && newY < m && newY >=0 && grid[newX][newY] == 1){
                            continue;
                        }
                        else{
                            ans++;
                        }
                    }
                }
            }
        }

        return ans;
    }
};