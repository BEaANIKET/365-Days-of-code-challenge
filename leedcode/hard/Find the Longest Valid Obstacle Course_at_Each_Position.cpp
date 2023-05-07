class Solution {
public:

  int firstgreater(vector<int>&temp,int a){
    return upper_bound(begin(temp),end(temp),a)-begin(temp);
  }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

      vector<int>ans;
      vector<int>temp;
      for(auto a:obstacles){
         if(temp.empty() || temp.back()<=a){
           temp.push_back(a);
           ans.push_back(temp.size());
         }
         else{
            int index=firstgreater(temp,a);
            temp[index]=a;
            ans.push_back(index+1);
         }
      }
      return ans;
    }
};