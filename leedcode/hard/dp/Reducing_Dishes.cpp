 //1.recursion + memoization
class Solution {
public:
int solve(vector<int>&sat,int index,int time, vector<vector<int>>&dp){
    if(index>=sat.size())
        return 0;

    if(dp[index][time]!=-1)
        return dp[index][time];
    

    int include=sat[index]*(time+1)+ solve(sat,index+1,time+1,dp);
    int exclude=0+solve(sat,index+1,time,dp);
    int ans=max(include,exclude);

    return dp[index][time]=ans;
}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return solve(satisfaction,0,0,dp);
    }
};

//tabulation
class Solution {
public:
    int solvetab(vector<int>&sat){
        int n=sat.size();
        vector<vector<int>>dp(n+1,(vector<int>(n+1,0)));

        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){

                 int include=sat[index]*(time+1)+ dp[index+1][time+1];
                 int exclude=0+dp[index+1][time];
                 int ans=max(include,exclude);

                 dp[index][time]=ans;
            }
        }
        return dp[0][0];
    }
      int maxSatisfaction(vector<int>& satisfaction) {
            sort(satisfaction.begin(),satisfaction.end());
          return solvetab(satisfaction);  
        }
    };

 //using variable for space optimization
     int solveSo(vector<int>&sat){
        int n=sat.size();
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);

        for(int index=n-1;index>=0;index--){
            for(int time=index;time>=0;time--){

                 int include=sat[index]*(time+1)+ next[time+1];
                 int exclude=0+next[time];
                 int ans=max(include,exclude);

                 curr[time]=ans;
            }
            next=curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
      return solveSo(satisfaction);  
    }
};