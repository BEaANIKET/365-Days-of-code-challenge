class Solution {
public:

int solve(const string &s,long k,vector<int>&dp,int idx){
    if(idx==s.length()){
        return 1;
    }
    if(s[idx]=='0'){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    long num=0;
    int ans=0;
    for(int i=idx;i<s.length();i++){
        num=num*10+s[i]-'0';
        if(num>k){
            break;
        }
        ans=ans+solve(s,k,dp,i+1);
        ans=ans%1000000007;

    }
    return dp[idx]=ans;

}
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.length(),-1);
       return  solve(s,k,dp,0);
    }
};
