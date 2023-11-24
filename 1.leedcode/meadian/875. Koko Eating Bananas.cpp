class Solution {
public:

    long long  calculate(vector<int>& piles,int mid){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            double val = (double) piles[i] / mid;
            // cout<<val<<endl;
            time+=ceil(val);
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=INT_MIN;

        for(int i=0;i<piles.size();i++){
            // start=min(start,piles[i]);
            end=max(end,piles[i]);
        }

        // cout<<start<<endl<<end;
        int result = INT_MAX;
        while(start<=end){
           int  mid=(start + end ) /2 ;
            long long  time = calculate(piles,mid);
            if(time <= h){
                // cout<<"mid = "<<mid<<"   time = "<<time<<endl;
                result=min(result,mid);
                end = mid-1;
            }
            else{
                // cout<<"else  " <<"mid = "<<mid<<"   time = "<<time<<endl;
                start=mid+1;
            }
        }
        return result;
    }
};