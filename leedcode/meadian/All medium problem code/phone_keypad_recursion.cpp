class Solution {
public:
void solve(string digits,string mapping[],vector<string>&ans,int index,string output){
  if(index>=digits.length()){
    ans.push_back(output);
    return ;
  }
  int number=digits[index]-'0';
  string value;
  value=mapping[number];
  for(int i=0;i<value.length();i++){
    output.push_back(value[i]);
    solve(digits,mapping,ans,index+1,output);
    output.pop_back();
  }
}
    vector<string> letterCombinations(string digits) {
        string output="";
        vector<string>ans;
        int index=0;
        if(digits.length()==0){
          return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,mapping,ans,index,output);
        return ans;
    }
};