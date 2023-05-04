class Solution {
public:
int solve(vector<int>&slices,int n,int index,vector<vector<int>>&dp,int endindex){
    if(n==0 || index>endindex){
        return 0;
    }
    if(dp[index][n]!=-1){
        return dp[index][n];
    }
    int case1=slices[index]+solve(slices,n-1,index+2,dp,endindex);
    int case2=0+solve(slices,n,index+1,dp,endindex);
   
    return dp[index][n]=max(case1,case2);
}
    int maxSizeSlices(vector<int>& slices) {
       int k=slices.size();
       vector<vector<int>>dp1(k,vector<int>(k,-1));
       int case1=solve(slices,k/3,0,dp1,k-2);

       vector<vector<int>>dp2(k,vector<int>(k,-1));
       int case2=solve(slices,k/3,1,dp2,k-1);
       return max(case1,case2); 
    }
};