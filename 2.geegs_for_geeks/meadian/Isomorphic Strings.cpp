//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends


class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length()) return false;
        
        int n = str1.length();
        // maps storing the frequency of each character
        unordered_map <char, int> mp1;
        unordered_map <char, int> mp2;
        for(int i=0;i<n;i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }
        
        // if distinct element count is different
        if(mp1.size() != mp2.size()) return false;
        
        // maps the char of first string to the char in second string
        unordered_map <char, char> match;
    
        for(int i=0;i<n;i++){
            // char in first , char in second string: p, q;    
            char p = str1[i];
            char q = str2[i];
            
            // camparing the frequency of char 
            if(mp1[p] != mp2[q]) return false;
            
            // if mapping is already done but now it conflict
            else if(match.find(p) != match.end() && match[p] != q){
                return false;
            }
            
            // if mapping is not done  or if done there is no conflict
            else if(match.find(p) == match.end() || match[p] == q){
                // decreasing the frequency as it is mapped
                mp1[p]--;
                mp2[q]--;
                // mapping from first to second string
                match[p] = q;
            }
        }
        
        return true;
    }
};



//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends