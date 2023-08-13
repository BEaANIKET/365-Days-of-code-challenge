//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>

class Solution {
  public:
  
    long long solve(int coins[],int n,int sum,int index,vector<vector<long long>>&dp){
        
        if(index>=n){
            return 0;
        }
        
        if(sum==0){
            return dp[index][0]=1;
        }
        
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        
        
        if(sum<coins[index]){
            return dp[index][sum]=solve(coins,n,sum,index+1,dp);
        }
        
        long long Take=solve(coins,n,sum-coins[index],index,dp);
        long long notTake=solve(coins,n,sum,index+1,dp);
        
        return dp[index][sum]=Take+notTake;
        
    }
    
    
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long>>dp(N+1,vector<long long>(sum+1,-1));
        return solve(coins,N,sum,0,dp);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends