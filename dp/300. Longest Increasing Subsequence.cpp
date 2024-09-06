class Solution {
public:

    int solve(vector<int>&nums,int i,int prev, vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        int inc=0;
        if( i==0 || prev == -1 || nums[i]>nums[prev]){
            inc = 1+solve(nums,i+1,i,dp);
        }

        int exc = solve(nums,i+1,prev,dp);

        return dp[i][prev+1] = max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;

        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+2 ,-1));
        return solve(nums,0,prev,dp);
    }
};