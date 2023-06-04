class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int one = -1;
        int nno = -1;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                one = i;
            }
        }
        
        while (one > 0) {
            swap(nums[one], nums[one - 1]);
            count++;
            one--;
        }
        
         for (int i = 0; i < n; i++) {
            if (nums[i] == n) {
                nno = i;
            }
        }
        
        while (nno < n - 1) {
            swap(nums[nno], nums[nno + 1]);
            count++;
            nno++;
        }
        
        return count;
    }
};
