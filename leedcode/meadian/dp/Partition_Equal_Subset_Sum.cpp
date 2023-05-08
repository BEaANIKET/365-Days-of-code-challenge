
//solve using recursion +memoization
class Solution {
public:

    bool solve(vector<int>&nums,int index,int target,vector<vector<int>>&dp){
      if(index>=nums.size())
        return 0;

      if(target<0)
        return 0;

      if(target==0)
        return 1;

      if(dp[index][target]!=-1)
        return dp[index][target];

      int option1=solve(nums,index+1,target-nums[index],dp);
      int option2=solve(nums,index+1,target,dp);

      return dp[index][target]=option1 || option2;
    }

   bool canPartition(vector<int>& nums) {
      int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
        }
        if(sum%2!=0)
          return false;
        return space_optimization(nums,0,sum/2);
    }
};

//by tabulation method ;
class Solution {
public:

    bool solvetab(vector<int>&nums,int t){
      vector<vector<int>>dp(nums.size()+1,vector<int>(t+1,0));
      for(int i=0;i<=nums.size();i++){
        dp[i][0]=1;
      }

      for(int index=nums.size()-1;index>=0;index--){
          for(int target=1;target<=t;target++){  

            bool option1=0; 
            if((target-nums[index])>=0)           
              option1=dp[index+1][target-nums[index]];

            bool option2=dp[index+1][target];
            dp[index][target]= option1 or option2;
          }
      }
      return dp[0][t];
    }
  
     bool canPartition(vector<int>& nums) {
      int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
        }
        if(sum%2!=0)
          return false;

        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return space_optimization(nums,0,sum/2,dp);
    }
};

//by space optimization by using only two vector;
class Solution {
public:

    bool space_optimization(vector<int>&nums,int t){
      vector<int>curr(t+1,0);
      vector<int>next(t+1,0);
      curr[0]=1;
      next[0]=1;

      for(int index=nums.size()-1;index>=0;index--){
          for(int target=0;target<=t/2;target++){  

            bool option1=0; 
            if((target-nums[index])>=0)           
              option1=next[target-nums[index]];

            bool option2=next[target];

            
            curr[target]=option1 or option2;
          }
          next=curr;
        }
        return next[t/2];
    }
  
    bool canPartition(vector<int>& nums) {
      int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
        }
        if(sum%2!=0)
          return false;
        return space_optimization(nums,sum);
    }
};