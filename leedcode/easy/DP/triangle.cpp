// by memoization;
class Solution {
public:
int solve(vector<vector<int>>&T,int i,int j, vector<vector<int>>&dp){
    if(i>=T.size())
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int option1=T[i][j]+solve(T,i+1,j,dp);
    int option2=T[i][j]+solve(T,i+1,j+1,dp);
    
    int ans=min(option1,option2);

    return dp[i][j]=ans;
}

     int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  solve(triangle,0,0,dp);

    }
};