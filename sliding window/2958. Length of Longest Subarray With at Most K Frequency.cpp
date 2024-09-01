class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> mp;

        int i = 0;
        int j = 0;

        int s = nums.size();
        int maxi = INT_MIN;

        while (i < s && j < s) {
            
            mp[nums[j]] ++;

            while (i < s && mp[nums[j]] > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            maxi = max(maxi, j-i + 1);
            j++;
            
        }

        return maxi;
    }
};