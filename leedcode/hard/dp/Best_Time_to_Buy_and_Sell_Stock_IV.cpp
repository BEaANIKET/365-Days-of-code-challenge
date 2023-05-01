class Solution {
public:
int solve(vector<int>& P,int k,int buy,int i,int n,vector<vector<vector<int>>>&dp){
    if(i>=n)
        return 0;

    if(dp[i][buy][k]!=-1)
        return dp[i][buy][k];

    int profit=0;
    if(k>0){
        if(buy){
            int buykro=-P[i]+solve(P,k,0,i+1,n,dp);
            int skipkro=0+solve(P,k,1,i+1,n,dp);
            profit=max(buykro,skipkro);
        }
        else{
           int sellkro=P[i]+solve(P,k-1,1,i+1,n,dp);
           int skipkro=0+solve(P,k,0,i+1,n,dp);
           profit=max(sellkro,skipkro);
        }
    }
    return dp[i][buy][k]= profit;
}
int solvetab(vector<int>& prices,int k){
    int n=prices.size();
     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
     int profit =0;
     for(int i=n-1;i>=0;i--){
         for(int j=0;j<=1;j++){
             for(int l=k;l>=1;l--){
                 if(k>0){
                    if(j){
                        int buykro=-prices[i]+dp[i+1][0][k];
                        int skipkro=0+dp[i+1][1][k];
                        profit=max(buykro,skipkro);
                    }
                    else{
                       int sellkro=prices[i]+dp[i+1][1][k-1];
                       int skipkro=0+dp[i+1][0][k];
                       profit=max(sellkro,skipkro);
                    }
                }

                
                    dp[i][j][l]= profit; 
            }
        }
    }

    return dp[0][1][k];
}
    int maxProfit(int k, vector<int>& prices) {
        // int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,k,1,0,n,dp);

    return solvetab(prices,k);
    }
};