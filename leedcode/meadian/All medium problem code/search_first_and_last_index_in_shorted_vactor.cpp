class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstindex=-1;
        int lastindex=-1;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==target){
            firstindex=i;
            break;
          }
        }
        for(int j=nums.size()-1;j>=0;j--){
          if(nums[j]==target){
            lastindex=j;
            break;
          }
        }
        ans.push_back(firstindex);
        ans.push_back(lastindex);
        return ans;
    }
};