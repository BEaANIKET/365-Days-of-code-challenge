// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        int maxi = 0;
        int currSum = 0;
        mp[0] = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }


            currSum += nums[i];

            if(mp.find(currSum) == mp.end()){
                mp[currSum] = i;
            }
            else{
                maxi = max(maxi,(i-mp[currSum]));
            }
        }

        return maxi ;
    }
};