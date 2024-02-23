class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>min;

        for(int i=0;i<nums.size();i++){
            min.push(nums[i]);
        }

        nums = {};
        while(!min.empty()){
            int n1 = min.top();
            min.pop();
            int n2 = min.top();
            min.pop();

            nums.push_back(n2);
            nums.push_back(n1);
        }

        return nums;

    }
};