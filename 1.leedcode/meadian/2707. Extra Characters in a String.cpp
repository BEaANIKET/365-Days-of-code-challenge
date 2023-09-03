class Solution {
public:

    int solve(string &s, set<string>&st,int index,vector<int >& dp){

        if(index>=s.length()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        string ans="";
        int extra=0;
        int mini=INT_MAX;

        for(int i=index;i<s.length();i++){
            ans.push_back(s[i]);
            if(st.find(ans)==st.end()){
                extra+=ans.length();
            }
            else {
                extra=0;
            }


            int remaingextra=solve(s,st,i+1,dp);

            int totalextra=extra+remaingextra;

            mini=min(mini,totalextra);

        }

           return dp[index]= mini;
    }
    int minExtraChar(string &s, vector<string>& dictionary) {
        set<string>st;
        for(auto s:dictionary){
            st.insert(s);
        }
        int n=s.length();

        vector<int>dp(n+1,-1);

        return solve(s,st,0,dp);
    }
};