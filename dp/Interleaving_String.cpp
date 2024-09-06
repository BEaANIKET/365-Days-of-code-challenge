class Solution {
public:

    bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(i==s1.length() && j==s2.length() && k==s3.length()){
            return true;
        }

        if( dp[i][j][k]!=-1){
            return  dp[i][j][k];
        }
    
        bool result =false;

        if(i<s1.length() && s1[i]==s3[k]){ 
          result =solve(s1,s2,s3,i+1,j,k+1,dp);
        }

        if( ! result && j<s2.length() && s2[j]==s3[k]){
           result = solve(s1,s2,s3,i,j+1,k+1,dp) ;
        }

        dp[i][j][k] = result ? 1 : 0;

        return result;
    }
    bool isInterleave(string s1, string s2, string s3) {

        vector<vector<vector<int>>>dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
       if(s1.length()+s2.length()!=s3.length())
        return false;

       return solve(s1,s2,s3,0,0,0,dp);
    }
};
