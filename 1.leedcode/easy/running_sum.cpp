class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
      int sum=0;
      int num;
      vector<int>ans;
        for(int i=0;i<nums.size();i++){
       num=nums[i];
       sum=sum+num;
    ans.push_back(sum);
        }
        return ans;
    }
};