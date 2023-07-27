//by recursion+memoization
class Solution {
public:
int solve(vector<int>&nums,int curr,int prev, vector<vector<int>>&dp){
    if(curr==nums.size()){
            return 0;
    }

    if(dp[curr][prev+1]!=-1)
        return dp[curr][prev+1];

    int option1=0;

    if(prev==-1 || nums[curr]>nums[prev]){
         option1=1+solve(nums,curr+1,curr,dp);
    }

        int option2= solve(nums,curr+1,prev,dp);

        return dp[curr][prev+1]=max(option1,option2);

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);
    }
};

//bu using tabulation;;

class Solution {
public:

    int solvetab(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int option1=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                option1=1+dp[curr+1][curr+1];
            }
                int option2= dp[curr+1][prev+1];

                dp[curr][prev+1]=max(option1,option2); 
            
        }
    }
        return dp[0][0];
}
    int lengthOfLIS(vector<int>& nums) {
        return solvetab(nums);
    }
};

//by using space optimization

class Solution {
public:

    int solvetab(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int option1=0;
                if(prev==-1 || nums[curr]>nums[prev]){
                option1=1+dp[curr+1][curr+1];
            }
                int option2= dp[curr+1][prev+1];

                dp[curr][prev+1]=max(option1,option2); 
            
        }
    }
        return dp[0][0];
}
    int lengthOfLIS(vector<int>& nums) {
        return solvetab(nums);
    }
};