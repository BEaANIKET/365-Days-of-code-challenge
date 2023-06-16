//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int expend_from_center(string s,int i,int j){
      while(i>=0 && j<s.length() && s[i]==s[j]){
          i--;
          j++;
          
      }
      return j-i-1;
  }
  
  
    string longestPalin (string s) {
      int start=0;
      int end=0;
      int len;
     
      for(int i=0;i<s.length();i++){
          int len1=expend_from_center(s,i,i);
          int len2=expend_from_center(s,i,i+1);
          len=max(len1,len2);
          if(end-start<len-1){
              start=i-(len-1)/2;
              end=i+(len/2);
          }
          
      }
     
        string st="";
        st.push_back(s[0]);
        string str=s.substr(start,(end-start)+1);
    
        if(str.length()==1){
             return st;
        }
    
         else{
            return str;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends