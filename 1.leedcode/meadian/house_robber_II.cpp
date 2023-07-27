class Solution {
public:
  int solve(vector<int>&nums){
   int n=nums.size();
 
    int prev2=nums[0];
 int prev1=max(nums[0],nums[1]);
  for(int i=2;i<n;i++){
   int sum=max(prev1,prev2+nums[i]);
   prev2=prev1;
   prev1=sum;
  }
return prev1;
}
   int rob(vector<int>& nums) {
      vector<int>first,second;
        int n=nums.size();
      if(n==1){
        return nums[0];
      }
      if(n==2){
        return max(nums[0],nums[1]);
      }
      for(int i=0;i<n;i++){
        if(i!=n-1){
          first.push_back(nums[i]);
        }
        if(i!=0){
          second.push_back(nums[i]);
        }
      }
  int ans= max(solve(first),solve(second));
    return ans;


    }
};