class Solution {
public:
int solve(vector<int>&obstacles,int currlen,int currpos,vector<vector<int>>&dp){
    int n=obstacles.size()-1;
    if(currpos==n)
        return 0;

    if(dp[currlen][currpos]!=-1)
        return dp[currlen][currpos];

    if(obstacles[currpos+1]!=currlen){
        return solve(obstacles,currlen,currpos+1,dp);
    }

     int ans=INT_MAX;
     for(int i=1;i<=3;i++){
         if(currlen!=i && obstacles[currpos]!=i)
             ans=min(ans,1+solve(obstacles,i,currpos,dp));
     }
      return dp[currlen][currpos] = ans;       
}

    int minSideJumps(vector<int>& obstacles) {
    int n=obstacles.size();
    vector<vector<int>>dp(4,vector<int>(n+1,-1));
      
        return solve(obstacles,2,0,dp);
    }
};