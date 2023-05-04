class Solution {
public:

    bool cheak(vector<int>&prev,vector<int>&curr){
        if(curr[0]<=prev[0] && curr[1]<=prev[1] && curr[2] <= prev[2]){
            return true;
        }
        else
            return false;
    }
    int solvetab(vector<vector<int>>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int option1=0;
                if(prev==-1 ||cheak(nums[curr],nums[prev])){
                option1=nums[curr][2]+dp[curr+1][curr+1];
            }
                int option2= dp[curr+1][prev+1];

                dp[curr][prev+1]=max(option1,option2); 
            
        }
    }
        return dp[0][0];
}
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &a : cuboids){
            sort(a.begin(),a.end());
        }
        sort(cuboids.begin(),cuboids.end());

        return solvetab(cuboids);
    }
};