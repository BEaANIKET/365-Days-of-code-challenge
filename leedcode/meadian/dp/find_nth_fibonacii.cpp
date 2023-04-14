#include<iostream>
#include<vector>
using namespace std;

// 1..approach
// here our time complacity is O(n);
// but our space complicity is O(n^2);
 int fib(int n,vector<int>&dp){
    if(n<=1){
        return n;
    }
    
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);

    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1);
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }

    cout<<fib(n,dp);
    return 0;
}
    

    // 2..approach
    // here our time complacity is O(n)
    // space complacity is O(n)
//     // tabulation method;
int main(){
 int n;
 cin>>n;
 vector<int>dp(n+1);   

    dp[0]=0;
    dp[1]=1;
for(int i=2;i<=n;i++){
    dp[i]=dp[i-1]+dp[i-2];
}    

cout<<dp[n];

    return 0;
}


// // 3..approach
// // second method here time complacity is O(n);
// // And space complacity is O(n);
int main(){
    int n;
    cin>>n;

 int prev1=0;
 int prev2=1;
 int cur=0;
 for(int i=0;i<=n;i++){
    cur=prev1+prev2;
    prev2=prev1;
    prev1=cur;
 }   

cout<<cur;

return 0;
}