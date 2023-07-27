class Solution {
public:
vector<vector<int>>ans;
void permu(vector<int>&nums,int idx){
  if(idx==nums.size()){
    ans.push_back(nums);
    return ;
  }

  for(int i=idx;i<nums.size();i++){
   swap(nums[i],nums[idx]);
   permu(nums,idx+1);
   swap(nums[i],nums[idx]);
  }

return;
}
    vector<vector<int>> permute(vector<int>& nums) {
         permu(nums,0);
         return ans;
    }
};
// 
// second method
// second method
// 
// 
class Solution {
public:
vector<vector<int>>ans;
 vector<vector<int>> permute(vector<int>& nums) {
   sort(nums.begin(),nums.end());
        do{
          ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};