class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1,idx2;
        for(int i=nums.size()-2;i>=0;i--){
          if(nums[i]<nums[i+1]){
            idx1=i;
            break;
          }

        }
        if(idx1<0){
          reverse(nums.begin(),nums.end());
        }
        else{
         
          for(int j=nums.size()-1;j>=0;j--){
          if(nums[j]>nums[idx1]){
           idx2=j;
           break;
          }
          }
          swap(nums[idx1],nums[idx2]);
          reverse(nums.begin()+idx1+1,nums.end());

        }
     
    }
};