class Solution {
public:

    #define ll long long 

    int chalkReplacer(vector<int>& chalk, int k) {


        int i = 0;
        ll sum = 0;
        for(int i=0; i<chalk.size(); i++){
            sum += chalk[i];
        }

        if(sum > k){
            while( k >= chalk[i] ){
                k -= chalk[i];
                i = (i+1) % chalk.size();
            }
        }

        k = k % sum;
        while( k >= chalk[i] ){
            k -= chalk[i];
            i = (i+1) % chalk.size();
        }
        
        return i;
    }
};