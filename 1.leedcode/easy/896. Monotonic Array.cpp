class Solution {
public:
    bool isMonotonic(vector<int>& nums) {

        int n=nums.size();
        int first=nums[0];
        int second=nums[n-1];
        int diff=first-second ;
        if(diff<0){
            for(int i=1;i<n;i++){
                if(nums[i]<nums[i-1]){
                    return false;
                }
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(nums[i]>nums[i-1]){
                    return false;
                }
            }
        }
        return true;
    }
};