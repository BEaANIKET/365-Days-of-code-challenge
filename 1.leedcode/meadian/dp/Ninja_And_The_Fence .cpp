#include <bits/stdc++.h> 
# define mod 1000000007
int add(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}
int mul(int a,int b){
    return ((a%mod)*1LL*(b%mod))%mod;
}
int solve(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    int ans=add(mul(solve(n-2,k),k-1),mul(solve(n-1,k),k-1));
    return ans;
}

int solvemem(int n,int k,vector<int>&dp){
     if(n==1){
        return k;
    }
    if(n==2){
        return add(k,mul(k,k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=add(mul(solvemem(n-2,k,dp),k-1),mul(solvemem(n-1,k,dp),k-1));
     return dp[n];
}


int solvetab(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=add(k,mul(k,k-1));
    for(int i=3;i<=n;i++){
        dp[i]=add(mul(dp[i-2],k-1),mul(dp[i-1],k-1));
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
   
  solvetab(n,k);
}
