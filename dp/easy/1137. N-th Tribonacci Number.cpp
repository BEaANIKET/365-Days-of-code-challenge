class Solution {
public:
    
 
    int tribonacci(int n) {

        if(n < 2){
            return n;
        }

        int a1 = 0, a2 = 1, a3 = 1;

        for(int i=3; i<=n; i++){
            int temp = a1 + a2 + a3;
            a1 = a2;
            a2 = a3; 
            a3 = temp;
        }

        return a3;

    }
};

class Solution {
public:
    
    int solve(int n, vector<int>& dp) {


        if(dp[n] != -1){
            return dp[n];
        }

        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 1;
        }

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp) + solve(n - 3, dp);
    }
    int tribonacci(int n) {

        vector<int> dp(n+1, -1);
        return solve(n, dp);

    }
};


class Solution {
public:
    
    int tribonacci(int n) {

        if(!n){
            return 0;
        }
        else if(n == 1 || n==2){
            return 1;
        }
        
        vector<int> dp(n+1, 0);

        dp[1] = 1;
        dp[2] = 1;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];

    }
};