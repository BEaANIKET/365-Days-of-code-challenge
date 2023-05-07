#define mod 1000000007
class Solution {
public:

    int solve(int dics,int face,int target,vector<vector<int>>&dp){
      if(target<0){
        return 0;
      }
      if(dics==0 && target!=0){
        return 0;
      }
      if(target==0 && dics!=0){
        return 0;
      }
      if(dics==0 && target==0){
        return 1;
      }
      if(dp[dics][target]!=-1){
        return dp[dics][target];
      }

      int ans=0;
      for(int i=1;i<=face;i++){
        ans=(ans+(solve(dics-1,face,target-i,dp))%mod)%mod;
      }
      return dp[dics][target]=(ans)%mod;
    }
      int numRollsToTarget(int n, int k, int target) {
           vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
             return solve(n,k,target,dp);
        }
    };

//by tabulation;
    class Solution {
    public:
    int solvetab(int d,int f,int t){
      vector<vector<int>>dp(d+1,vector<int>(t+1,0));
      dp[0][0]=1;
      for(int dice=1;dice<=d;dice++){
        for(int target=1;target<=t;target++){
           int ans=0;
              for(int i=1;i<=f;i++){
                if(target-i>=0)
                  ans=(ans+(dp[dice-1][target-i])%mod)%mod;
              }
              dp[dice][target]=ans;
        }
      } 
      return dp[d][t];
    }

      int numRollsToTarget(int n, int k, int target) {       
           return solvetab(n,k,target);          
        }
    };


//optimize solution in O(target) time ;
    class Solution {
    public:
    int solve_space_optimization(int d,int f,int t){
       vector<int>curr(t+1,0);
       vector<int>prev(t+1,0);
       prev[0]=1;
       for(int dice=1;dice<=d;dice++){
         for(int target=1;target<=t;target++){
            int ans=0;
               for(int i=1;i<=f;i++){
                 if(target-i>=0)
                   ans=(ans+(prev[target-i])%mod)%mod;
               }
               curr[target]=ans;
         }
         prev=curr;
       } 
      return prev[t];
    }
    int numRollsToTarget(int n, int k, int target) {
      return  solve_space_optimization(n,k,target);
    }
};