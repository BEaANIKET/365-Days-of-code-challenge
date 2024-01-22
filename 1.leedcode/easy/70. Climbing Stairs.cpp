class Solution {
public:

   

    int solve(int n,int pos,vector<int>&dp){
        if(pos>n){
            return 0;
        }

        if(dp[pos] != -1){
            return dp[pos];
        }

        if(pos == n){
            return 1;
        }

        int opt1 = solve(n,pos+1,dp);
        int opt2 = solve(n,pos+2,dp);

        return dp[pos] = opt1+opt2;
    }
    int climbStairs(int n) {
         vector<int>dp(n+1,-1);
        return solve(n,0,dp);
    }
};