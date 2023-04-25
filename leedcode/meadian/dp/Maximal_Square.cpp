class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
     vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0 || j==0){
                    if(matrix[i][j]=='1'){
                        dp[i][j]=1;
                    }
                }
                    else{
                        if(matrix[i][j]=='1'){
                            dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));

                        }
                    }
                    ans=max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};