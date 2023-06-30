class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        int start=0;
        int end=n-1;;
        int peak=0;

        while(start<end){

            int mid=start + (end-start)/2;

            if(nums[mid]<=nums[mid+1]){
                start=mid+1;
                peak=mid+1;
            }
            else{
                end=mid;
                peak=mid;
            }
        }
        return peak;
    }
};