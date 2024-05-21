class Solution {
public:

    vector<vector<int>> result ;
    
    void solve(vector<int>& nums, int i, vector<int>& ans){
        if(i >= nums.size()){
            result.push_back(ans);
            return ;
        }

        ans.push_back(nums[i]);
        solve(nums, i+1, ans);
        ans.pop_back();
        solve(nums, i+1, ans);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> ans;
        solve(nums, 0, ans);
        return result;
    }
};