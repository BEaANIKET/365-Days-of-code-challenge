class Solution {
public:

void solve(vector<int>&candies,int extcandies,vector<bool>&ans){
  int maxi=0;
  for(int i=0;i<candies.size();i++){
 maxi=max(maxi,candies[i]);
  }
  for(int i=0;i<candies.size();i++){
    int sum=candies[i]+extcandies;
    if(sum>=maxi){
      ans.push_back(true);
    }
    else{
      ans.push_back(false);
    }
  }
}
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
      vector<bool>ans;
      solve(candies,extraCandies,ans);
      return ans;
    }
};