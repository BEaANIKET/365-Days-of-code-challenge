class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int idx1=-1;
        int idx2=-1;
        int j=numbers.size()-1;
        while(i<j){
          int sum=numbers[i]+numbers[j];
          if(sum==target){
          idx1=i+1;
          idx2=j+1;
          return vector{idx1,idx2};
          }
          else if(sum<target){
            i++;
          }
          else if(sum>target){
            j--;
          }
         

        }
        return vector{idx1,idx2};
    }
};