class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>stk;
        int thirdEle=INT_MIN;
        int n=nums.size();
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]<thirdEle){
                return true;
            }

            while(!stk.empty() && stk.top()<nums[i]){
                thirdEle=stk.top();
                stk.pop();

            }

            stk.push(nums[i]);
        }

        return false;
    }
};