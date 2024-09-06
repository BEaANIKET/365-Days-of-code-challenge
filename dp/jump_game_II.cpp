class Solution {
public:
    int jump(vector<int>& nums) {
      int des=0;
      int pos=0;
      int jump=0;
      for(int i=0;i<nums.size()-1;i++){
          des=max(des,nums[i]+i);
          if(pos==i){
              pos=des;
              jump++;
          }
      }  
      return jump;
    }
};