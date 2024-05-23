class Solution {
public:
    int ans = 0;

    void solve(vector<int>& nums, int k, int index, unordered_map<int, int>& s) {

        if (index >= nums.size()) {
            ans++;
            return;
        }

        solve(nums, k, index + 1, s);

        if (!s[nums[index] - k] && !s[k + nums[index]]) {

            s[nums[index]]++;
            solve(nums, k, index + 1, s);
            s[nums[index]]--;

        }

        return;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> s;
        solve(nums, k, 0, s);

        return ans - 1;
    }
};