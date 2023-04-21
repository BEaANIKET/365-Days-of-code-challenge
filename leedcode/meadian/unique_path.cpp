class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<dp[0].size();i++){
            dp[0][i]=1;
        }
        for(int j=0;j<dp.size();j++){
            dp[j][0]=1;
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[i].size();j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};