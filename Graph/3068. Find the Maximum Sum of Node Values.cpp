class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        

        long long sum = 0;
        long long mini = INT_MAX;
        int count = 0;

        for(long long val : nums){

            if(abs(val ^ k) > val){

                count ++;
                sum += val ^ k;

            }else{

                sum += val;
            }

            mini = min(mini, abs(val - (val^k)));
        }


        if(count % 2 != 0){
            return sum - mini;
        }
        else{
            return sum;
        }
    }
};