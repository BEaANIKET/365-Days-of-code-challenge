//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 int dij(int N, int M, vector<vector<int>> A, int x, int y)
  {      priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
      q.push({0,0,0});
      vector<vector<bool>>vis(N,vector<bool>(M,false));
      int ans=INT_MAX;
      while(q.size()>0)
      {
          vector<int>v=q.top();
          q.pop();
          int i=v[1],j=v[2],cnt=v[0];
          if(i<N&&j<M)
          {
            if(vis[i][j]==false)
            {   vis[i][j]=true;
                if(i==x&&j==y)
                {
                    ans=min(ans,cnt);
                    return ans;
                }
             else
             {    if(j-1>=0&&vis[i][j-1]==false&&A[i][j-1]==1)
                {
                    q.push({cnt+1,i,j-1});
                }
                
                if(j+1<M&&vis[i][j+1]==false&&A[i][j+1]==1)
                {
                    q.push({cnt+1,i,j+1});
                }
                
                if(i-1>=0&&vis[i-1][j]==false&&A[i-1][j]==1)
                {
                    q.push({cnt+1,i-1,j});
                }
                
                if(i+1<N&&vis[i+1][j]==false&&A[i+1][j]==1)
                {
                    q.push({cnt+1,i+1,j});
                }
              }
            }    
          }
     }
    return ans;
  }

int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        int ans=dij(N,M,A,X,Y);
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends