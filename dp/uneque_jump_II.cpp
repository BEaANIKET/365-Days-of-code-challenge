class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();

        if(nums[0][0]==1){
            return 0;
        }

        vector<vector<int>>dp(n,vector<int>(m));

        for(int i=0;i<n;i++){
            if(nums[i][0]!=1){
                dp[i][0]=1;
            }
            else break;
        }
        for(int j=0;j<m;j++){
            if(nums[0][j]!=1){
                dp[0][j]=1;
            }
            else break;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else dp[i][j]=0;
            }
        }
        return dp[n-1][m-1];
    }
};