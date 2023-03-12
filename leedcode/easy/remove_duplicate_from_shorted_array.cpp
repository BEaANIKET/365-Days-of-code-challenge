class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i=1,k;
    for(k=1;k<nums.size();k++){
      if (nums[k-1]!=nums[k]){
        nums[i]=nums[k];
        i++;
      }
    }
    return i;
    }

};