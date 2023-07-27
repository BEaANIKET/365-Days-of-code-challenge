// 1. first solution 
// by memoization;
class Solution {
public:
int solve(vector<int>&days,vector<int>&costs,int n,int index,vector<int>&dp){
    if(index>=n){
        return 0;
    }


    if(dp[index]!=-1)
        return dp[index];


    int option1=costs[0]+solve(days,costs,n,index+1,dp);

    int i;

    for(i=index;i<n && days[i]<days[index]+7;i++);
    int option2 =costs[1]+solve(days,costs,n,i,dp);


    for(i=index;i<n && days[i] < days[index]+30;i++);
    int option3 =costs[2]+solve(days,costs,n,i,dp);
    
     dp[index]=min(option1,min(option2,option3));

     return dp[index];

}
  int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solve(days,costs,n,0,dp);
};

// 2. second solution 
// by tabulation;
class Solution {
public:
int solvetab(vector<int>days,vector<int>costs){
    int n=days.size();
    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
    int option1=costs[0]+dp[k+1];

    int i;

    for(i=k;i<n && days[i]<days[k]+7;i++);
    int option2 =costs[1]+dp[i];


    for(i=k;i<n && days[i] < days[k]+30;i++);
    int option3 =costs[2]+dp[i];
    
     dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
}


    int mincostTickets(vector<int>& days, vector<int>& costs) {
      return solvetab(days,costs);
    }
};