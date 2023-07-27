//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int getSingle(int arr[], int n) {
	    unordered_map<int,int>umap;
	    for(int i=0;i<n;i++){
	        umap[arr[i]]++;
	    }
	    
	    for(int i=0;i<n;i++){
	        int key=arr[i];
	        auto temp=umap.find(key);
	        if((temp->second%2)!=0){
	            return key;
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getSingle(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends