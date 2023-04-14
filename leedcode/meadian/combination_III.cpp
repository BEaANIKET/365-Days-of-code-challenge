class Solution {
public:
void helper(vector<vector<int>>&ans,vector<int>ans2,int k,int n,int sum,int idx){
  if(sum==n && k==0){
    ans.push_back(ans2);
    return ;
  }
  if(sum>n){
    return ;
  }
for(int i=idx;i<=9;i++){
  if(i>n){
    break;
  }
  ans2.push_back(i);
  helper(ans,ans2,k-1,n,sum+i,i+1);
  ans2.pop_back();
}
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ans2;
        helper(ans,ans2,k,n,0,1);
        return ans;
    }
};