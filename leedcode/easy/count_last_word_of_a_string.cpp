class Solution {
public:
    int lengthOfLastWord(string s) {
       int length=s.length();
       bool flag=false;
      int count=0;
      for(int i=length-1;i>=0;i--){
        if (s[i]!=' '){
          count++;
          flag=true;
          continue;

        }
        else if (flag){
          break;
        }
      }
      return count;
    }
};