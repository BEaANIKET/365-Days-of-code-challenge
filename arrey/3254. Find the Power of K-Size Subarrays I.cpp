class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans(nums.size() - k + 1, -1);

        for(int i = 0; i <= nums.size() - k; i++) {
            bool isValid = true;
            int maxElement = nums[i];

            for(int j = i + 1; j < i + k; j++) {
                if(nums[j] != nums[j-1] + 1) {
                    isValid = false;
                    break;
                }
                maxElement = max(maxElement, nums[j]);
            }

            if(isValid) {
                ans[i] = maxElement;
            }
        }

        return ans;
    }
};
