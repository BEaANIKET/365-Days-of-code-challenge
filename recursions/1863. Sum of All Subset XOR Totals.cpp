class Solution {
public:

    int solve(vector<int>& nums, int index, int currXor){

        if(index >= nums.size()){
            return currXor;
        }

        int opt1 = solve(nums, index+1, currXor^nums[index]);
        int opt2 = solve(nums, index+1, currXor);

        return opt1 + opt2;
    }


    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};