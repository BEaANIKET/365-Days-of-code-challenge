class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
          if(i>0 && nums[i]==nums[i-1]){
            continue;
          }
          for(int j=i+1;j<n-2;j++){
            if( j>i+1 && nums[j]==nums[j-1]){
              continue;
            }
            long long  tsum=(long long)target-(long long )(nums[i]+nums[j]);
            int l=j+1;
            int k=n-1;
            while(l<k){
              if(nums[l]+nums[k]==tsum){
                vector<int>oneAns={nums[i],nums[j],nums[l],nums[k]};
                ans.push_back(oneAns);
                while(l<k && nums[l]==nums[l+1]){
                  l++;
                }
                while(l<k && nums[k]==nums[k-1]){
                  k--;
                }
               l++;
               k--;
              }
              else if(nums[l]+nums[k]<tsum){
                l++;
              }
              else{
                k--;
              }
            }
          }
        }
       return ans; 
    }
};