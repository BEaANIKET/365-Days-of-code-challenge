class Solution {
public:
vector<vector<int>>ans;

void helper(vector<int>&candidates,int target,int i,int cursum,vector<int>temp){
  if(cursum>target){
    return ;
  }
  if(i==candidates.size()){
    if(cursum==target){
      ans.push_back(temp);

    }
    return ;
  }

  cursum+=candidates[i];
  temp.push_back(candidates[i]);
  helper(candidates,target,i+1,cursum,temp);
 cursum-=candidates[i];
  temp.pop_back();

while(i+1 < candidates.size() && candidates[i]==candidates[i+1]){
  i++;
}

  helper(candidates,target,i+1,cursum,temp);

}
 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        helper(candidates,target,0,0,temp);
     sort(ans.begin(),ans.end());
        return ans; 
    }
};