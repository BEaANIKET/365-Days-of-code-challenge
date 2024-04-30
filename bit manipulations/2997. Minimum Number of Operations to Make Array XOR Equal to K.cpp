class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int totalXOR = 0;
        for(int i=0; i<nums.size(); i++){
            totalXOR ^= nums[i];
        }

        int diff = totalXOR ^ k;

        return __builtin_popcount(diff);
    }
};