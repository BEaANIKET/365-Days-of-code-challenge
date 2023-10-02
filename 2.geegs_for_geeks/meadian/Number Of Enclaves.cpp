//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int count(int n,int m,vector<vector<int>>& grid){
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
    
    bool issafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
  
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        grid[i][j]=0;
        int ax[4]={1,-1,0,0};
        int ay[4]={0,0,1,-1};
        
        for(int k=0;k<4;k++){
            int nx=ax[k]+i;
            int ny=ay[k]+j;
            
            if(issafe(nx,ny,n,m,grid)){
                dfs(nx,ny,n,m,grid);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            int j=0;
            if(grid[i][j]==1){
                dfs(i,j,n,m,grid);
            }
            
            j=m-1;
            if(grid[i][j]==1){
                dfs(i,j,n,m,grid);
            }
        }
        
        for(int j=0;j<m;j++){
            int i=0;
            if(grid[i][j]==1){
                dfs(i,j,n,m,grid);
            }
            
            i=n-1;
            if(grid[i][j]==1){
                dfs(i,j,n,m,grid);
            }
        }
        return count(n,m,grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends