//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
   vector<string>find_permutation(string s)
		{
		    vector<string> v;
		    sort(s.begin(),s.end());
		    string str=s;
		    v.push_back(str);
		    while(true){
		        next_permutation(str.begin(),str.end());
		        v.push_back(str);
		        if (str==s) break;
		    }
		    v.pop_back();
		    return v;
		}
};




//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends