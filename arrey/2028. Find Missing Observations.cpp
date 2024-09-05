class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        
        int total_sum = mean * (n + m);
        
        int sum_of_known_rolls = accumulate(rolls.begin(), rolls.end(), 0);
        
        int sum_of_missing_rolls = total_sum - sum_of_known_rolls;
        
        if (sum_of_missing_rolls < n || sum_of_missing_rolls > 6 * n) {
            return {};
        }
        
        vector<int> result(n, sum_of_missing_rolls / n);
        int remainder = sum_of_missing_rolls % n;
        
        for (int i = 0; i < remainder; ++i) {
            result[i]++;
        }
        
        return result;
    }
};
