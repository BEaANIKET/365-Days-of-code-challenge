class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0,m=s.length(),n=t.length();
        for(int i=0;i<n;i++){
          if(s[j]==t[i]){
            j++;
          }
        }
        return (j==m);
    }
};