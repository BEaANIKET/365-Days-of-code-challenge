class Solution {
public:
   void solve(vector<int>&nums,int k,int idx,vector<vector<int>> & ans,vector<int>&curr){
  if(idx==nums.size()){
     if(curr.size()==k){
       ans.push_back(curr);
     }
       return;
     }

     solve(nums,k,idx+1,ans,curr);
     curr.push_back(nums[idx]);
     solve(nums,k,idx+1,ans,curr);
     curr.pop_back();
  }

   
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>>ans;
      vector<int>curr;
       vector<int>nums;
       for(int i=1;i<=n;i++){
       nums.push_back(i);
       } 
       solve(nums,k,0,ans,curr);
       return ans;
    }
};