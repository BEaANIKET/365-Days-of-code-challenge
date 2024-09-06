class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>&dp){
        if (i>=nums1.size() || j>=nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+solve(nums1,nums2,i+1,j+1,dp);
        }
    
            int option1=solve(nums1,nums2,i+1,j,dp);
            int option2=solve(nums1,nums2,i,j+1,dp);
            return dp[i][j]= max(option1,option2);
    }
    int solvetab(vector<int>&nums1,vector<int>&nums2){
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                 if(nums1[i]==nums2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                int option1=dp[i+1][j];
                int option2=dp[i][j+1];
                dp[i][j]= max(option1,option2);
                }
            }
        }
        return dp[0][0];
    }
    int space_optimazation(vector<int>&nums1,vector<int>&nums2){
        vector<int>curr(nums2.size()+1,0);
        vector<int>next(nums2.size()+1,0);

         for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                 if(nums1[i]==nums2[j]){
                    curr[j]=1+next[j+1];
                }
                else{
                int option1=next[j];
                int option2=curr[j+1];
                    curr[j]= max(option1,option2);
                }
            }
          swap(curr,next);
            
        }
        return next[0];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size(),-1));
    //    return solve(nums1,nums2,0,0,dp);
       return space_optimazation(nums1,nums2);
    }
};