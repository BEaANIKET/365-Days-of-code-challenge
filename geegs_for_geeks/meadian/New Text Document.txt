//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    int solve(vector<int>&price,int n,int index,int buy , vector<vector<int>>&dp){
        if(index>=n){
            return 0;
        }
        
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        
        int profit=0;
   
        if(buy){
            int op1=-price[index]+solve(price,n,index+1,0,dp);
            int op2=solve(price,n,index+1,1,dp);
            profit= max(op1,op2);
        }
        else{
            int op1=price[index]+solve(price,n,index+1,1,dp);
            int op2=solve(price,n,index+1,0,dp);
            profit=max(op1,op2);
            
        }
            return dp[index][buy]=profit;
    }
    
    int solve1(vector<int>&price,int n){
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                
                int profit=0;
   
                if(buy){
                     int op1=-price[index]+dp[index+1][0];
                     int op2=dp[index+1][1];
                    profit= max(op1,op2);
                 }
                else{
                    int op1=price[index]+dp[index+1][1];
                    int op2=dp[index+1][0];
                    profit=max(op1,op2);
            
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return solve(prices,n,0,1,dp);
        return solve1(prices,n);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends