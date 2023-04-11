class Solution {
public:

 void findall (string cur,int o,int c,vector<string>&ans,int n){
   if(cur.length()==2*n){
     ans.push_back(cur);
     return ;
   }
   if(o<n){
    
     findall(cur+'(',o+1,c,ans,n);
   }
   if(c<o){
   
     findall(cur+')',o,c+1,ans,n);
   }
  
 }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        findall("(",1,0,ans,n);
        return ans ;
    }
  
};