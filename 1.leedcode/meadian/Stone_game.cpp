class Solution {
public:
    bool solve(vector<int>& piles, int i, int j, int alices, int bob, int flag,vector<vector<int>>&dp) {
        if (i > j || j < i) {
            if (alices >= bob) // Corrected from > to >=
                return 1;
            else
                return 0;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        if (flag == 1) {      
            return dp[i][j]=max(solve(piles, i + 1, j, alices + piles[i], bob, 0,dp),  solve(piles, i, j - 1, alices + piles[j], bob, 0,dp));
        }

        if (flag == 0) {           
            return dp[i][j]=max(solve(piles, i + 1, j, alices, bob + piles[i], 1,dp),solve(piles, i, j - 1, alices, bob + piles[j], 1,dp)); 
        }

        return false;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(piles, 0, n - 1, 0, 0, 1,dp);
    }
};
