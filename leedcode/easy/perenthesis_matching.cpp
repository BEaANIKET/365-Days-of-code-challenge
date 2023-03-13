class Solution {
public:
    bool isValid(string s) {
       stack<char>ss;
       for(int i=0;i<s.length();i++){
         char ch=s[i];
         if(ch=='(' || ch=='{' || ch=='['){
           ss.push(ch);
         }
         else{
           
           if(!ss.empty()){
             char top=ss.top();
      if(ch==')' && top =='(' || ch==']' && top=='[' || ch=='}' && top=='{'){
               ss.pop();
             }
             else{
               return false;
             }
             
           }
           else{
              return false;
           }
         }
       }
       if (ss.empty()){
         return true;
       } 
       else{
         return false;
       }
    }
};