class Solution {
public:
    int result = 0;
    
    int solve(string &s, int k, int i, char prev, vector<vector<int>>& dp) {
        if (i >= s.length()) {
            return 0;
        }
        
        if (dp[i][prev - 'a'] != -1) {
            return dp[i][prev - 'a'];
        }

        int takeCurr = 0;
        if (abs(s[i] - prev) <= k) {
            takeCurr = 1 + solve(s, k, i + 1, s[i], dp);
        }
        int skipCurr = solve(s, k, i + 1, prev, dp);
        
        dp[i][prev - 'a'] = max(takeCurr, skipCurr);
        
        return dp[i][prev - 'a'];
    }

    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(26, -1)); 
        
        int maxLen = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            maxLen = max(maxLen, solve(s, k, 0, c, dp));
        }
        
        return maxLen;
    }
};
