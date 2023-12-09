class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int n=arr.size();
        int high=n-1;

        while(low<=high){
            int mid=(high+low)/2;
            int mis=arr[mid] - (mid+1);

            if(mis < k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            
        }
        return k + high + 1;
    }
};