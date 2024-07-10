class Solution {
public:

    int maxProfit(vector<int>& prices) {
        // int profit = 0;
        // int maxi = 0;
        // map<int, int> mp;
        // for(int i=prices.size()-1; i>=0; i--){
        //     maxi = max(maxi, prices[i]);
        //     mp[i] = maxi;
        // }

        // for(int i=0; i<prices.size(); i++){
        //     int rightMaxi = mp[i];
        //     profit = max(profit, rightMaxi-prices[i]);
        // }

        // return profit ;

        int mini = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            profit = max(profit, prices[i]-mini);
            mini = min(prices[i], mini);
        }

        return profit;
    }
};