//solve using recursion + memoization;
class Solution {
public:
  int solve(vector<int>&nums1,vector<int>&nums2,int index,int swapped,vector<vector<int>>&dp){
    if(index==nums1.size())
      return 0;

    int prev1=nums1[index-1];
    int prev2=nums2[index-1];
    int ans =INT_MAX;

    if(dp[index][swapped]!=-1)
      return dp[index][swapped];
    if(swapped)
      swap(prev1,prev2);

    if(nums1[index]>prev1 && nums2[index]>prev2){
      ans=solve(nums1,nums2,index+1,0,dp);
    }
    if(nums1[index]>prev2 && nums2[index]>prev1){
      ans=min(ans,1+solve(nums1,nums2,index+1,1,dp));
    }
    return dp[index][swapped] = ans;
  }
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.begin(),-1);
      nums2.insert(nums2.begin(),-1);
      vector<vector<int>>dp(nums1.size()+1,vector<int>(2,-1));
     return solve(nums1,nums2,1,0,dp);
    
    }
};

//solve using tabulation;
class Solution {
public:
  int solvetab(vector<int>&nums1,vector<int>&nums2){
    vector<vector<int>>dp(nums1.size()+1,vector<int>(2,0));
    for(int index=nums1.size()-1;index>=1;index--){
      for(int swapped=1;swapped>=0;swapped--){
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        int ans =INT_MAX;

        if(swapped)
          swap(prev1,prev2);

          if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=dp[index+1][0];
          }
          if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+dp[index+1][1]);
          }
          dp[index][swapped] = ans; 
      }
    }
    return dp[1][0];
  }
  int minSwap(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.begin(),-1);
      nums2.insert(nums2.begin(),-1);
     
      return solvetab(nums1,nums2);
       
    }
};

//space optimization by using variable
class Solution {
public:
  int spaceoptimization(vector<int>&nums1,vector<int>&nums2){
    int swapp=0;
    int noswapp=0;
    int currswapp=0;
    int currnoswapp=0;
    for(int index=nums1.size()-1;index>=1;index--){
      for(int swapped=1;swapped>=0;swapped--){
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        int ans =INT_MAX;

        if(swapped)
          swap(prev1,prev2);

          if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=noswapp;
          }
          if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+swapp);
          }
         if(swapped){
          currswapp = ans;
         } 
         else{
          currnoswapp = ans;
         }
      }
      swapp=currswapp;
      noswapp=currnoswapp;
    }
    return min(swapp,noswapp);
  }
   
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.begin(),-1);
      nums2.insert(nums2.begin(),-1);
      return spaceoptimization(nums1,nums2);
    }
};