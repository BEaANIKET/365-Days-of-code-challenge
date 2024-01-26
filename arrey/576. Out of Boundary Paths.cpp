class Solution {
public:

    #define mod 1000000007
    vector<int>x{-1,0,1,0};
    vector<int>y{0,-1,0,1};


    int solve(int m,int n,int maxmove ,int startrow,int startcol,int i,int j,vector<vector<vector<int>>>&dp){

        if(i < 0 || i >= m || j<0 || j>=n){
            return 1;
        }

        if(dp[maxmove][i][j] != -1){
            return dp[maxmove][i][j];
        }

        int ans =0;
        for(int k=0;k<4;k++){
            if(maxmove>0)
                ans = ((ans%mod )+ (solve(m,n,maxmove-1,startrow,startcol,i+x[k],j+y[k],dp))%mod)%mod;
        }

        return  dp[maxmove][i][j] = ans;

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(51,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,startRow,startColumn,dp);
    }
};