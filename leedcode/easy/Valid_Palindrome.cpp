class Solution {
public:
    bool isPalindrome(string s) {
        vector<int>v;
       for(int i=0;i<s.length();i++){
           auto ch=s[i];
           if(isalpha(ch) || isdigit(ch) ){
               if(isupper(ch)){
                   v.push_back(tolower(ch));
               }
               else {
                   v.push_back(ch);
               }
           }
           else {
               continue;
           }
       }

       int S=0;
       int e=v.size()-1;
       while(e>S){
           if(v[S]!=v[e]){
               return false;
           } 
           S++;
           e--;        
       }
       return true; 
    }
};