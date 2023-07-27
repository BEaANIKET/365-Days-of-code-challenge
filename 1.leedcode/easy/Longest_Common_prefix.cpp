class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string x="";
        if (strs.size()==0){
          return x;
        }
        for ( int i=0;i<strs[0].size();i++){
          char ch=strs[0][i];
          for ( int j=0;j<strs.size();j++){
            if (ch!=strs[j][i]){
              return x;
            }  
        
          }
          x=x+ch;
        }
        return x;
    }
};