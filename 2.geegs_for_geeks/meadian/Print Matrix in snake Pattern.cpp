//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        
        int i=0;
        int j=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        
        while(i<m && j<n && i>=0 && j>=0){
            
            while(i<m && j<n && i>=0 && j>=0){
                ans.push_back(matrix[i][j]);
                j++;
            }
            j=n-1;
            i++;
            while(i<m && j<n && i>=0 && j>=0){
                ans.push_back(matrix[i][j]);
                j--;
            }
            j=0;
            i++;
        
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends