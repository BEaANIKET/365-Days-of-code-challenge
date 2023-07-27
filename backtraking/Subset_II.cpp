class Solution {
public:
vector<vector<int>>ans;
  int j=0;
void helpsub(vector<int>&nums,vector<int>&subset,int i){
  if(i==nums.size()){
    ans.push_back(subset);
    return ;
  }
  subset.push_back(nums[i]);
  helpsub(nums,subset,i+1);

  subset.pop_back();
  while(i+1 < nums.size() && nums[i]==nums[i+1]){
    i++;
  }
  helpsub(nums,subset,i+1);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        vector<int>subset;
        helpsub(nums,subset,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};