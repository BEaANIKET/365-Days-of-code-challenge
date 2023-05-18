// class Solution {
// public:

//     vector<int> countBits(int n) {
//         vector<int>ans(n+1);
//         for(int i=0;i<=n;i++){
//             if(i%2==0){
//                 ans[i]=ans[i/2];
//             }
//             else{
//                 ans[i]=ans[i/2]+1;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0); 
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        
        return dp;
    }
};

// class Solution {
// public:

// vector<int> solve(int n){
//     vector<int>v;
//     while(n>0){
//         int rem=n%2;
//         v.push_back(rem);
//         n/=2;
//     }
//     return v;
// }
//     vector<int> countBits(int n) {
//         vector<int>ans;

//         for(int i=0;i<=n;i++){
//             int count=0;
//             vector<int>num =solve(i);
//             for(int j=0;j<num.size();j++){
//                 if(num[j]==1)
//                     count++;
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };