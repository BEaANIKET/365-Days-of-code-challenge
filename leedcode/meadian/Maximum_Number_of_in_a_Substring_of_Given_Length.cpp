class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=INT_MIN;
        int count=0;
        
       for(int i=0;i<s.length();i++){
           char ch=s[i];
           if(ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u'){
               count++;
           }
           if(i>=k){
               if(s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u'){
                   count--;
               }
           }
           ans=max(ans,count);
       }
       return ans; 
    }
};