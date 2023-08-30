class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        long long operation=0;
        int n=nums.size();

        for(int i=n-2;i>=0;i--){

            if(nums[i]<=nums[i+1]){
                continue;
            }

            int part=nums[i]/nums[i+1];
            if(nums[i]%nums[i+1]!=0)
                part++;
        

            operation+=part-1;

            nums[i]=nums[i]/part;

        }

        return  operation;
    }
};