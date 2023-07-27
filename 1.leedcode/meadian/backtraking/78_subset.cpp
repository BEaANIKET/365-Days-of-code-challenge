class Solution {
public:
vector<vector<int>>ans;

void helper(vector<int>nums,vector<int>subset,int ind){
  if(ind==nums.size()){
    ans.push_back(subset);
    return;
  }
  //Take case
  subset.push_back(nums[ind]);
  helper(nums,subset,ind+1);

  //not Take case

  subset.pop_back();
  helper(nums,subset,ind+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        helper(nums,subset,0);
        return ans;
    }
};