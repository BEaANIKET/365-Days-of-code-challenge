class Solution {
public:
void solve(vector<string>&ans,string s,string temp,int i){
  if(i>=s.length()){
    ans.push_back(temp);
    return ;
  }

  temp.push_back(s[i]);
  solve(ans,s,temp,i+1);
  temp.pop_back();

  if(isalpha(s[i])){
    if(isupper(s[i])){
      temp.push_back(tolower(s[i]));
    }
    else{
      temp.push_back(toupper(s[i]));
    }
  solve(ans,s,temp,i+1);
  temp.pop_back();

  }
}
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(ans,s,"",0);
        return ans;
    }
};