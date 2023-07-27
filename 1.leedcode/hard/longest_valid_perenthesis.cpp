class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>str;
        stack<int>index;
        index.push(-1);
        int maxi=0;
        int count =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' ){
                str.push(s[i]);
                 index.push(i);
            }
            else{
                if (s[i]==')'  && !str.empty() && str.top()=='('){
               str.pop();
               index.pop(); 
               maxi=max(maxi,i-index.top());
           }
           else {
               index.push(i);
           }
            }
          }
        return maxi;
    }
};