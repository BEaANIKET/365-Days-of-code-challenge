// first solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        if(prices.size()<=1){
            return profit;
        }
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=(prices[i]-prices[i-1]);
            }
        }
    return profit;
    }
};

class Solution {
public:
// by memoization
// second solution
<!-- space comp.=O(n)
    Time comp.=O(n) -->
int solvemem(vector<int>&prices,int buy,int index,vector<vector<int>>&dp){
    if(index==prices.size()){
        return 0;
    }
    if(dp[index][buy]!=-1)
         return dp[index][buy];

    int profit=0;
    if(buy){
        int buykro=-prices[index]+solve(prices,0,index+1,dp);
        int skipkro=0+solve(prices,1,index+1,dp);
        profit=max(buykro,skipkro);
    }
    else{
        int sellkro=prices[index]+solve(prices,1,index+1,dp);
        int skipkro=0+solve(prices,0,index+1,dp);
        profit=max(sellkro,skipkro);
    }
    return dp[index][buy]=profit;
}
// by tabulation;
// third solution
<!-- space comp.=O(n)
    Time comp.=O(n) -->
int solvetab(vector<int>&prices){
    int n=prices.size();
   vector<vector<int>>dp(n+1,vector<int>(2,0));
   int profit=0;
   for(int index=n-1;index>=0;index--){
       for(int buy=0;buy<=1;buy++){
          if(buy){
        int buykro=-prices[index]+dp[index+1][0];
        int skipkro=0+dp[index+1][1];
        profit=max(buykro,skipkro);
    }
    else{
        int sellkro=prices[index]+dp[index+1][1];
        int skipkro=0+dp[index+1][0];
        profit=max(sellkro,skipkro);
    }
     dp[index][buy]=profit; 
       }
   }
  return dp[0][1];
}

// space optimazation
// forth solution
<!-- space comp.=O(1)
    Time comp.=O(n) -->
int solveSo(vector<int>&prices){
    int n=prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);
    int profit=0;
      for(int index=n-1;index>=0;index--){
       for(int buy=0;buy<=1;buy++){
          if(buy){
        int buykro=-prices[index]+next[0];
        int skipkro=0+next[1];
        profit=max(buykro,skipkro);
    }
    else{
        int sellkro=prices[index]+next[1];
        int skipkro=0+next[0];
        profit=max(sellkro,skipkro);
    }
     curr[buy]=profit; 
  }
    next=curr;
 }
  return next[1];
}



    int maxProfit(vector<int>& prices) {
        //  <!-- this is for solvemem function
            //   call for second solution -->
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solvemem(prices,1,0,dp);
         
        //  <!-- This is for solvetab function
        //      call for third solution -->
        return solvetab(prices);

        // <!-- This is for solveSo function 
        //   call for  forth solution -->
        return solveSo(prices);
    }
};